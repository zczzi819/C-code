#coding=utf-8
# @Author: yangenneng
# @Time: 2018-01-17 15:42
# @Abstract：多元线性回归(Multiple Regression)算法

from numpy import genfromtxt
import numpy as np
from sklearn import linear_model

datapath=r"C:\Users\Administrator\Desktop\ex2.txt"
#从文本文件中提取数据并转为numpy Array格式
deliveryData = genfromtxt(datapath,delimiter=',')

print("data")
# print deliveryData

# 读取自变量X1(运送英里数),X2(运送次数)
x= deliveryData[:,:-1]
# 读取因变量(运送时间)
y = deliveryData[:,-1]

print(X,Y)
# 调用线性回归模型
lr = linear_model.LinearRegression()
# 装配数据
lr.fit(x, y)

print(lr)

print("coefficients:")
print(lr.coef_)

print("intercept:")
print(lr.intercept_)

#预测
xPredict = [102,6]
yPredict = lr.predict(xPredict)
print("predict:")
print(yPredict)



