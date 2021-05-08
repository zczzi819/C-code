function tree = make_tree(patterns, targets, inc_node, discrete_dim, maxNbin, base)
%Build a tree recursively

[Ni, L]    					= size(patterns);
Uc         					= unique(targets);
tree.dim					= 0;
%tree.child(1:maxNbin)	= zeros(1,maxNbin);
tree.split_loc				= inf;

if isempty(patterns),
    return
end

%When to stop: If the dimension is one or the number of examples is small
if ((inc_node > L) | (L == 1) | (length(Uc) == 1)), %剩余训练集只剩一个，或太小，小于inc_node，或只剩一类，退出
    H					= hist(targets, length(Uc));  %返回类别数的直方图  
    [m, largest] 	= max(H); %更大的一类，m为大的值，即个数，largest为位置，即类别的位置  
    tree.Nf         = [];
    tree.split_loc  = [];
    tree.child	 	= Uc(largest);%直接返回其中更大的一类作为其类别  
    return
end

%Compute the node's I
for i = 1:length(Uc),
    Pnode(i) = length(find(targets == Uc(i))) / L;
end
Inode = -sum(Pnode.*log(Pnode)/log(2));

%For each dimension, compute the gain ratio impurity
%This is done separately for discrete and continuous patterns
delta_Ib    = zeros(1, Ni);
split_loc	= ones(1, Ni)*inf;

for i = 1:Ni,
    data	= patterns(i,:);
    Ud      = unique(data);
    Nbins	= length(Ud);
    if (discrete_dim(i)),
        %This is a discrete pattern
        P	= zeros(length(Uc), Nbins);
        for j = 1:length(Uc),
            for k = 1:Nbins,
                indices 	= find((targets == Uc(j)) & (patterns(i,:) == Ud(k)));
                P(j,k) 	= length(indices);
            end
        end
        Pk          = sum(P);
        P           = P/L;
        Pk          = Pk/sum(Pk);
        info        = sum(-P.*log(eps+P)/log(2));
        delta_Ib(i) = (Inode-sum(Pk.*info))/-sum(Pk.*log(eps+Pk)/log(2));
    else
        %This is a continuous pattern
        P	= zeros(length(Uc), 2);

        %Sort the patterns
        [sorted_data, indices] = sort(data);
        sorted_targets = targets(indices);

        %Calculate the information for each possible split
        I	= zeros(1, L-1);
        for j = 1:L-1,
            %for k =1:length(Uc),
            %    P(k,1) = sum(sorted_targets(1:j)        == Uc(k));
            %    P(k,2) = sum(sorted_targets(j+1:end)    == Uc(k));
            %end
            P(:, 1) = hist(sorted_targets(1:j) , Uc);
            P(:, 2) = hist(sorted_targets(j+1:end) , Uc);
            Ps		= sum(P)/L;
            P		= P/L;
            
            Pk      = sum(P);            
            P1      = repmat(Pk, length(Uc), 1);
            P1      = P1 + eps*(P1==0);
            
            info	= sum(-P.*log(eps+P./P1)/log(2));
            I(j)	= Inode - sum(info.*Ps);
        end
        [delta_Ib(i), s] = max(I);
        split_loc(i) = sorted_data(s);
    end
end

%Find the dimension minimizing delta_Ib
[m, dim]    = max(delta_Ib);
dims        = 1:Ni;
tree.dim    = dim;

%Split along the 'dim' dimension
Nf		= unique(patterns(dim,:));
Nbins	= length(Nf);
tree.Nf = Nf;
tree.split_loc      = split_loc(dim);

%If only one value remains for this pattern, one cannot split it.
if (Nbins == 1)
    H				= hist(targets, length(Uc));
    [m, largest] 	= max(H);
    tree.Nf         = [];
    tree.split_loc  = [];
    tree.child	 	= Uc(largest);
    return
end

if (discrete_dim(dim)),
    %Discrete pattern
    for i = 1:Nbins,
        indices         = find(patterns(dim, :) == Nf(i));
        tree.child(i)	= make_tree(patterns(dims, indices), targets(indices), inc_node, discrete_dim(dims), maxNbin, base);
    end
else
    %Continuous pattern
    indices1		   	= find(patterns(dim,:) <= split_loc(dim));
    indices2	   		= find(patterns(dim,:) > split_loc(dim));
    if ~(isempty(indices1) | isempty(indices2))
        tree.child(1)	= make_tree(patterns(dims, indices1), targets(indices1), inc_node, discrete_dim(dims), maxNbin, base+1);
        tree.child(2)	= make_tree(patterns(dims, indices2), targets(indices2), inc_node, discrete_dim(dims), maxNbin, base+1);
    else
        H				= hist(targets, length(Uc));
        [m, largest] 	= max(H);
        tree.child	 	= Uc(largest);
        tree.dim                = 0;
    end
end