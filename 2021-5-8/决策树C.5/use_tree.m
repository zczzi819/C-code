function targets = use_tree(patterns, indices, tree, discrete_dim, Uc)
%Classify recursively using a tree

targets = zeros(1, size(patterns,2));

if (tree.dim == 0)
    %Reached the end of the tree
    targets(indices) = tree.child;
    return
end

%This is not the last level of the tree, so:
%First, find the dimension we are to work on
dim = tree.dim;
dims= 1:size(patterns,1);

%And classify according to it
if (discrete_dim(dim) == 0),
    %Continuous pattern
    in				= indices(find(patterns(dim, indices) <= tree.split_loc));
    targets		= targets + use_tree(patterns(dims, :), in, tree.child(1), discrete_dim(dims), Uc);
    in				= indices(find(patterns(dim, indices) >  tree.split_loc));
    targets		= targets + use_tree(patterns(dims, :), in, tree.child(2), discrete_dim(dims), Uc);
else
    %Discrete pattern
    Uf				= unique(patterns(dim,:));
    for i = 1:length(Uf),
        if any(Uf(i) == tree.Nf) %Has this sort of data appeared before? If not, do nothing
            in   	= indices(find(patterns(dim, indices) == Uf(i)));
            targets	= targets + use_tree(patterns(dims, :), in, tree.child(find(Uf(i)==tree.Nf)), discrete_dim(dims), Uc);
        end
    end
end

%END use_tree


