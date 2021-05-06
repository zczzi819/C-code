clc
clear
%% 数据准备
%read data
load test_data.text
load train_data.text
train_data(find(train_data(:,3)==-1),3)=0;
test_data(find(test_data(:,3)==-1),3)=0;

%% 计算类中心
[m,n]=size(train_data);
cen1=zeros(1,2);cen0=zeros(1,2);%定义类中心
sum1=zeros(1,2);sum0=zeros(1,2);
num1=0;num0=0;
for i=1:m
    if train_data(i,3)==1
        sum1(1,1)=sum1(1,1)+train_data(i,1);
        sum1(1,2)=sum1(1,2)+train_data(i,2);
        num1=num1+1;
    end
    if train_data(i,3)==0
        sum0(1,1)=sum0(1,1)+train_data(i,1);
        sum0(1,2)=sum0(1,2)+train_data(i,2);
        num0=num0+1;
    end
end
cen0=sum0/num0;cen1=sum1/num1;

%% 计算类内散度
Sw=zeros(2,2);
for i=1:m
    if train_data(i,3)==1
        Sw=Sw+(train_data(i,[1 2])-cen1(1,:))'*(train_data(i,[1 2])-cen1(1,:));
    end
    if train_data(i,3)==0
        Sw=Sw+(train_data(i,[1 2])-cen0(1,:))'*(train_data(i,[1 2])-cen0(1,:));
    end
end

%% 计算类间散度
Sb=(cen0-cen1)'*(cen0-cen1);

%% 结果显示
[L,D]=eigs(Sw\Sb',1);%计算最大特征值和特征向量
%显示投影线
k=L(1)/L(2);
b=0;
xx=-15:25;
yy=k*xx;
plot(xx,yy)
hold on
for i=1:m
    if train_data(i,3)==1
        plot(train_data(i,1),train_data(i,2),'ro');
    end
    if train_data(i,3)==0
        plot(train_data(i,1),train_data(i,2),'bo');
    end
end
new_data=zeros(m,n-1);
new_data(:,1)=(k*train_data(:,2)+train_data(:,1))/(k*k+1);
new_data(:,2)=k*new_data(:,1);
new_data(:,3)=train_data(:,3);
hold on
for i=1:m
    if new_data(i,3)==1
        plot(new_data(i,1),new_data(i,2),'r+','MarkerSize', 5);
    end
    if new_data(i,3)==0
        plot(new_data(i,1),new_data(i,2),'b+','MarkerSize', 5);
    end
end

Sw
Sb

