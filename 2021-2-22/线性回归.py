from numpy import *
import matplotlib.pyplot as plt


def loadDataSet(fileName):
    numFeat = len(open(fileName).readline().split('\t')) - 1  # 得到特征值的个数
    dataMat = [];
    labelMat = []
    fr = open(fileName)  # 打开文件
    for line in fr.readlines():  # 读取整行
        lineArr = []
        curLine = line.strip().split('\t')  # 将一行的不同特征分开
        for i in range(numFeat):
            lineArr.append(float(curLine[i]))
        dataMat.append(lineArr)
        labelMat.append(float(curLine[-1]))
    return dataMat, labelMat


def standRegres(xArr, yArr):
    xMat = mat(xArr);
    yMat = mat(yArr).T
    xTx = xMat.T * xMat
    ws = xTx.I * (xMat.T * yMat)  # 求 w=(x.T*x).I*x.T*y
    return ws


a, b = loadDataSet('ex0.txt')
ws = standRegres(a, b)
print(ws)
x = arange(0, 1, 0.01)
plt.plot([i[1] for i in a], b, 'or')
plt.plot(x, float(ws[0]) + float(ws[1]) * x, 'g')
plt.show()