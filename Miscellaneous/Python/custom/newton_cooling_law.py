# Newton's Law of Cooling.

import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

k = float(input("Heat Transfer Coefficient: k = "))
T_0 = float(input("Ambient Temperature: T_0 = "))

def cooling_law(T,t):
    dTdt = -k * (T - T_0)                           # Newton's Law of Cooling.
    return dTdt

T0 = float(input("Initial Temperature: T0 = "))     # Initial Condition.

t = np.linspace(0,40,120)

T = odeint(cooling_law,T0,t)
T = np.array(T).flatten()

plt.plot(t,T)
plt.title(r"Newton's Law of Cooling. $\frac{dT}{dt} = k(T - T_{0})$", fontsize=18)
plt.xlabel('Time.')
plt.ylabel('Temperature. T(t)')
plt.savefig("Law_of_Cooling.png")
plt.show()

T_exact = T_0 + (T0 - T_0) * np.exp(-k*t)           # Exact Solution of Newton's Law of Cooling.
T_diff = np.abs(T_exact - T)
plt.semilogy(t, T_diff)                             # Logarithmic Graph.
plt.ylabel("Error")
plt.xlabel("t")
plt.title("Error in Numerical Integration.")
plt.savefig('Error.png')
plt.show()
