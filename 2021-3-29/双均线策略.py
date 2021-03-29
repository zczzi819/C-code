import tushare as ts
import pandas as pd
from pandas import DataFrame,Series
import matplotlib.pyplot as plt

df=pd.read_csv('./maotai.csv')
#print(df)
df.drop(labels='Unnamed: 0',axis=1,inplace=True)#这里1是行，0是列
#print(df)
df['date']=pd.to_datetime(df['date'])#date列转为时间序列类型
df.set_index('date',inplace=True)#将date列设置为行索引
print(df)
#计算该股票历史数据的5日均线和30日均线
#什么是均线？
#对于每一个交易日，都可以计算出前n天的移动平均值，然后把这些移动平均值连起来，成为一条线，就叫做N日移动平均线，移动平均线常用线有5天、10天、30天、60天、120天和240天的指标
#5天和10天是短线操作的参照指标，称做日均线指标
#30天和60天是中期均线指标，称做季均线指标
#120天和240天的是长期均线指标，称做年均线指标
#均线的计算方法：MA=(c1+c2+c3+.....+cn)/N,c:某日收盘价 N：移动平均周期(天数)
ma5=df['close'].rolling(5).mean()#计算5日均值
print(ma5)
ma30=df['close'].rolling(30).mean()#计算30日均值
print(ma30)
#画图
plt.plot(ma5)
#plt.show()
plt.plot(ma30)
#plt.show()

#plt.show(ma5)
#分析输出所有金叉日期和死期
#股票分析技术的金叉和死叉，可以简单解释为：
#分析指标中的两根线，一根为短时间内的指标线，另一根为较长时间的指标线
#如果短时间的指标线方向拐头向上，并且穿过了较长时间的指标线，这种状态叫“金叉”
#如果短时间的指标线方向拐头向下，并且穿过了较长时间的指标线，这种状态叫“死叉”
#一般情况下，出现金叉后，操作趋于买入；死叉则趋向卖出。当然，金叉和死叉只是分析指标之一，要和其他很多指标配合使用，才能增加操作的准确性
ma5=ma5[30:]
ma30=ma30[30:]
print(ma5)
print(ma30)
s1=ma5<ma30
print(s1)
s2=ma5>ma30
print(s2)
death_ex=s1&s2.shift(1)#判断死叉的条件
print(death_ex)
df=df[30:]
print(df.loc[death_ex])#死叉对应的行数据
death_date=df.loc[death_ex].index
print(death_date)
#金叉
golden_ex=~(s1|s2.shift(1))#判断金叉的条件
print(golden_ex)
gold_date=df.loc[golden_ex].index
print(gold_date)