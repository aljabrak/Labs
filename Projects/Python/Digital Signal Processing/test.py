from numpy import *
from matplotlib.pyplot import *
from scipy import *
from pandas import *
from sklearn import *

file = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'class']
data = read_csv(file, names = names)
print(data)
print(data.shape)
print(data.head(30))
print(data.describe())
print(data.groupby('class').size())
data.plot(kind = 'box', subplots = True, layout = (2, 2), sharex = False, sharey = False)
show()
