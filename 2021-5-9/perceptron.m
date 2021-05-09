clc
clear
load test_data.text
load train_data.text
x_train=train_data(:,[1,2]);
x_test=test_data(:,[1,2]);
y_train=train_data(:,3);
y_test=test_data(:,3);
x1_min=min(x_train(:,1));x2_min=min(x_train(:,2));
x1_max=max(x_train(:,1));x2_max=max(x_train(:,2));
m=size(x_train,1);%m=样本点个数
plotData2(x_train,y_train);
w=[0;0];b=0;
lr=0.005;%学习率
time=1000;%迭代次数
for j=1:time
   for i=1:m
       if (((w'*x_train(i,:)'+b)*y_train(i))<=0)
           w=w+lr*y_train(i)*x_train(i,:)';
           b=b+lr*y_train(i);
       end
   end
end
hold on
x=x1_min:0.1:x1_max;
y=(-w(1)*x-b)/w(2);
plot(x,y,'-r','Linewidth',3)
error_train=0;
for i=1:m
    if (((w'*x_train(i,:)'+b)*y_train(i))<=0)
        error_train=error_train+1;
    end
end
acc_train=1-(error_train/m)
error_test=0;
n=size(x_test,1);
for i=1:n
    if (((w'*x_test(i,:)'+b)*y_test(i))<=0)
        error_test=error_test+1;
    end
end
acc_test=1-(error_test/m)
plotData2(x_test,y_test);
hold on
plot(x,y,'-r','Linewidth',3)
    
 