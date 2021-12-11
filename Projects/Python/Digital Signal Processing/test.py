from numpy import *
from matplotlib.pyplot import *
from scipy import *
import pandas
from sklearn import *


file = 'earthquakes.csv'
names = ['impact.magnitude', 'location.depth', 'location.distance']
data = pandas.read_csv(file, names = names)
print(data)
print(data.shape)
print(data.head(30))
print(data.describe())
