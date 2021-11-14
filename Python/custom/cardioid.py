import numpy as np
from matplotlib import pyplot as plt
theta = np.linspace(0, 2*np.pi, 1000)

r = 1 + np.sin(theta)
plt.polar(theta, r, 'r')   
plt.legend() 
plt.savefig("Cardioid.png")
plt.show() 

