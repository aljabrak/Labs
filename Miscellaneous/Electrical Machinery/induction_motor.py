from numpy import *
from matplotlib.pyplot import *

Vt = float(input("Enter Terminal Voltage: Vt = "))
fse = float(input("Enter System Frequency: fse = "))
P = int(input("Enter Number of Poles: P = "))
CONFIG = str(input("Y or D: "))
R1 = float(input("Enter Stator Resistance: R1 = "))
X1 = float(input("Enter Stator Reactance: X1 = "))
Xm = float(input("Enter Magnetizing Reactance: Xm = "))
R2 = float(input("Enter Rotor Resistance: R2 = "))
X2 = float(input("Enter Rotor Reactance: X2 = "))



if CONFIG is "Y":
    Vp = Vt / sqrt(3)

else:
    Vp = Vt


if fse is None:
    wsync = (2 * pi / 60) * 5000
else:
    nsync = (120 / P) * fse
    wsync = (2 * pi / 60) * nsync


wm = [j for j in arange(0, wsync, 0.01)]
s = [1 - (w / wsync) for w in wm]
Vth = Vp * Xm / (sqrt(R1**2 + (X1 + Xm)**2))
Rth = R1 * (Xm / (X1 + Xm))**2
Xth = X1


T = []

for val in s:
    A = (3*Vth*R2/val) / wsync
    B = (Rth + R2/val)**2 + (Xth + X2)**2
    t = A / B
    T.append(t)

T_min = min(T)
s_min = min(s)
T_max = max(T)
s_max = max(s)
print("Minimum Torque: Tmin = ", T_min)
print("Minimum Slip: Smin = ", s_min)
print("Maximum Torque: Tmax = ", T_max)
print("Maximum Slip: Smax = ", s_max)


plot(wm, T)
grid()
show()