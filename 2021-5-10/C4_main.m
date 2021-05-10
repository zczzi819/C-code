clc
clear
%% 数据处理
fid=fopen('lenses.txt','r');
C=textscan(fid,'%s');
sta=fclose(fid);
for i=1:length(C{1,1})
data{i}=C{1,1}{i};
end
data=reshape(data,5,24);
data=data';
for i=1:length(data)
    age{i}=data{i,1};
    spe{i}=data{i,2};
    ast{i}=data{i,3};
    tar{i}=data{i,4};
    label{i}=data{i,5};
end
age=unique(age);spe=unique(spe);ast=unique(ast);tar=unique(tar);label=unique(label);
data_fin=zeros(24,5);
for i=1:size(data)
    data_fin(i,1)=find(strcmp(data{i,1},age));
    data_fin(i,2)=find(strcmp(data{i,2},spe));
    data_fin(i,3)=find(strcmp(data{i,3},ast));
    data_fin(i,4)=find(strcmp(data{i,4},tar));
    data_fin(i,5)=find(strcmp(data{i,5},label));
end

%% 训练
train_patterns=data_fin(:,1:(size(data_fin,2)-1));
train_targets=data_fin(:,size(data_fin,2))';
test_patterns=[2 1 1 2];
test_targets_predict = C4_5(train_patterns', train_targets, test_patterns', 3, 10);
predict=label{test_targets_predict};
disp(predict)
