import tushare as ts
import pandas as pd
from pandas import DataFrame,Series
import numpy as np
#获取某只股票的历史行情数据
#code:字符串形式的股票代码
df=ts.get_k_data(code='600519',start='2010-01-01')
#print(df)
#将互联网上获取的股票数据存放到本地
#df.to_csv('./maotai.csv')#调用to_xxx方法将df中的数据写入到本地进行存储
#将本地存储数据读入到df
#df=pd.read_csv('./maotai.csv')
#print(df.head())
#需要对读取出来的数据进行相关处理
#删除df中指定的一列
#df.drop(labels='Unnamed: 0',axis=1,inplace=True)#这里一是行，0是列，
#print(df.head())#查看前n行，默认为5
#print(df['date'].dtype)#查看每一列数据元素
#print(df.info())#查看每一列数据元素
df['date']=pd.to_datetime(df['date'])#date列转为时间序列类型
#print(df.info())
df.set_index('date',inplace=True)#将date列设置为行索引
#print(df)
#输出该股票所有开盘比前日收盘跌幅超过2%的日期
#伪代码：(开盘—前日收盘)/前日收盘<-0.02
#print((df['open']-df['close'].shift(1))/df['close'].shift(1)<-0.002)#向下移一位
#将布尔值作为原数据的行索引取出True对应的行数据
#print(df.loc[(df['open']-df['close'].shift(1))/df['close'].shift(1)<-0.002])
#print(df.loc[(df['open']-df['close'].shift(1))/df['close'].shift(1)<-0.002].index)
#分析
#时间节点：2010-2020
#一手股票：100支股票
#买：一个完整的年需要买入1200支股票
#卖：一个完整年需要卖出1200支股票
#买卖股票的单价：开盘价

#买股票：找每个月的第一个交易日对应的行数据(捕获开盘价)——每月的第一行数据
#根据月份从原始数据中提取指定的数据
#每月第一个交易日对应的行数据
df_monthly=df.resample('M').first()#数据重新取样
#print(df_monthly)
#买入股票花费的总金额
cost=df_monthly['open'].sum()*100
print(cost)

#卖出股票到手的钱
#特殊的情况：2020年买入的股票卖不出去
#print(df.resample('A').last())
#将2020最后一行切出去
df_yearly=df.resample('A').last()[:-1]
#print(df_yearly)
#卖出股票到手的钱
resv=df_yearly['open'].sum()*1200
print(resv)
#最后手中剩余的股票需要估量其价值计算到总收益中
last_money=200*df['close'][-1]
#计算总收益
print(last_money+resv+cost)






