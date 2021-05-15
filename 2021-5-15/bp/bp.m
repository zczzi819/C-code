clc
clear
%% 训练数据预测数据
load test_data.text
load train_data.text
x_train=train_data(:,[1,2])';
x_test=test_data(:,[1,2])';
y_train=train_data(:,3)';
y_test=test_data(:,3)';
y_train(find(y_train==-1))=0;
y_test(find(y_test==-1))=0;

%输入数据归一化
[x_trainn,x_trainps]=mapminmax(x_train);

%% BP网络训练
% %初始化网络结构
net=newff(x_trainn,y_train,10);

net.trainParam.epochs=1000;
net.trainParam.lr=0.1;
net.trainParam.goal=0.0000004;

%% 网络训练
net=train(net,x_trainn,y_train);

%% BP网络预测
%预测数据归一化
inputn_test=mapminmax('apply',x_test,x_trainps);
 
%网络预测输出
BPoutput=sim(net,inputn_test);

%% 结果分析
%根据网络输出找出数据属于哪类
BPoutput(find(BPoutput<0.5))=0;
BPoutput(find(BPoutput>=0.5))=1;


%预测正确率
rightnumber=0;
for i=1:size(y_test,2)
    if BPoutput(i)==y_test(i)
       rightnumber=rightnumber+1;
    end
end
rightratio=rightnumber/size(y_test,2)*100
