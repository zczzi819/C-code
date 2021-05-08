function test_targets = C4_5(train_patterns, train_targets, test_patterns, inc_node, Nu)

% Classify using Quinlan's C4.5 algorithm
% Inputs:
% 	training_patterns   - Train patterns ������������������
%	training_targets	- Train targets  1�ж��У�����ѵ����������
%   test_patterns       - Test  patterns ������������������
%	inc_node            - Percentage of incorrectly assigned samples at a node
%    inc_nodeΪ��ֹ����ϲ�������ʾ������С��һ����ֵ�����ݹ飬������Ϊ5-10
%  Nu is to determine whether the variable is discrete or continuous (the value is always set to 10)
%
% Outputs
%	test_targets        - Predicted targets 1��m�У��еĳ����ǲ��������ĸ�����

%NOTE: In this implementation it is assumed that a pattern vector with fewer than 10 unique values (the parameter Nu)
%is discrete, and will be treated as such. Other vectors will be treated as continuous

[Ni, M]		= size(train_patterns);%��������ΪNI*M�ľ�������M��ʾѵ������������NiΪ����ά��ά��
inc_node    = inc_node*M/100;

%Find which of the input patterns are discrete, and discretisize the corresponding
%dimension on the test patterns
discrete_dim = zeros(1,Ni);
for i = 1:Ni,
    Ub = unique(train_patterns(i,:));
    Nb = length(Ub);
    if (Nb <= Nu),
        %This is a discrete pattern
        discrete_dim(i)	= Nb;
        dist            = abs(ones(Nb ,1)*test_patterns(i,:) - Ub'*ones(1, size(test_patterns,2)));
        [m, in]         = min(dist);
        test_patterns(i,:)  = Ub(in);
    end
end

%Build the tree recursively
%disp('Building tree')
tree            = make_tree(train_patterns, train_targets, inc_node, discrete_dim, max(discrete_dim), 0);

%Classify test samples
%disp('Classify test samples using the tree')
test_targets    = use_tree(test_patterns, 1:size(test_patterns,2), tree, discrete_dim, unique(train_targets));
