from numpy import *
from matplotlib.pyplot import *
from scipy import *
import pandas
from sklearn import *


file = 'earthquakes.csv'
names = ['impact.gap', 'impact.magnitude', 'location.depth', 'location.distance']

data = pandas.read_csv(file, names)
print(data)

