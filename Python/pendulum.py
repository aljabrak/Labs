import numpy as np
from matplotlib import pyplot as plt

L = 1                                                         #length of pendulum string.  [m]
g = 9.80665                                                   #gravitational acceleration. [m/sq.s]
t = np.arange(0, (1/2)*(np.pi), 0.1)                          #angle. [radians]
T0 = 2 * np.pi * np.sqrt(L/g)                                 #time period due to small angle of swing.
T = 2 * np.pi * np.sqrt(L/g) * (1+ (1/2)**2*np.sin(t/2)**2)   #time period due to very large angle of swing.
plt.plot(t, T, label = r'$T = T_{0}\left(1 + \left(\frac{1}{2}\right)^{2}\mathrm{sin}(\theta)^{2} + \cdots \right)$')
plt.axhline(T0, color = 'r', label = r'$T_{0} = 2\pi \sqrt{ \frac{L}{g} }$') #plot constant lines (y = k).
plt.xlabel("Angle.")
plt.ylabel("Time Period.")
plt.grid()
plt.title(r'$T = 2\pi \sqrt{ \frac{L}{g} }\left(1 + \left(\frac{1}{2}\right)^{2}\mathrm{sin}(\theta)^{2} + \cdots \right)$')
plt.legend()
plt.savefig("pendulum.png")
plt.show()
