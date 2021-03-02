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


def lwlr(testPoint, xArr, yArr, k=1.0):
    xMat = mat(xArr);
    yMat = mat(yArr).T
    m = shape(xMat)[0]  # m为行数
    weights = mat(eye((m)))  # 创建m*m的单位矩阵
    for j in range(m):
        diffMat = testPoint - xMat[j, :]
        weights[j, j] = exp(diffMat * diffMat.T / (-2.0 * k ** 2))  # 对角线上的元素改为exp(|x(i)-x|/(-2k*k))
    xTx = xMat.T * (weights * xMat)
    ws = xTx.I * (xMat.T * (weights * yMat))  # 求  w=(x.T*W*x).I*x.T*W*y
    return testPoint * ws


def lwlrTestPlot(xArr, yArr, k=1.0):
    y = zeros(shape(yArr))
    Arr = [i[1] for i in xArr]
    xCopy = mat(xArr);
    x = mat(Arr).T  # 将列表转化为矩阵
    xCopy.sort(0);
    x.sort(0)  # 给矩阵从小到大排序
    for i in range(shape(xArr)[0]):
        y[i] = lwlr(xCopy[i], xArr, yArr, k)  # 调用lwlr函数
    return x, y


a, b = loadDataSet(r'C:\Users\Administrator\Desktop\ex0.txt')
plt.figure(1)
c, d = lwlrTestPlot(a, b, 1)
plt.plot([i[1] for i in a], b, 'or')
plt.plot(c, d, 'g')
plt.figure(2)
c, d = lwlrTestPlot(a, b, 0.03)
plt.plot([i[1] for i in a], b, 'or')
plt.plot(c, d, 'g')
plt.figure(3)
c, d = lwlrTestPlot(a, b, 0.008)
plt.plot([i[1] for i in a], b, 'or')
plt.plot(c, d, 'g')
plt.show()