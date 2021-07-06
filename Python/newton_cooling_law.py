# Newton's Law of Cooling.

import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

k = float(input("Heat Transfer Coefficient: k = "))
T_0 = float(input("Ambient Temperature: T_0 = "))

def cooling_law(T,t):
    dTdt = -k * (T - T_0)
    return dTdt

T0 = 5

t = np.linspace(0,40,120)

T = odeint(cooling_law,T0,t)

plt.plot(t,T)
plt.title(r"Newton's Law of Cooling. $\frac{dT}{dt} = k(T - T_{0})$", fontsize=18)
plt.xlabel('time')
plt.ylabel('T(t)')
plt.savefig("Law_of_Cooling.png")
plt.show()
