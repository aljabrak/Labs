from matplotlib.pyplot import *

R = 287.058                                   #Specific Gas Constant for Dry Air. [J/Kg.K]
d0 = 1.2922                                   #Density of Air at 273.17 K.
M = 0.02897                                   #Molar Mass of Dry Air. [Kg/mol]
b = 3.4E-3                                    #Volumteric Expansion Coefficient of Air. [1/K]

T_values = []
P_values = []

start = 1
while start == 1:
    T = float(input("Temperature [K]: "))
    T_values.append(T)
    d = d0 * (1 + b * T)
    P = (d * R * T)/M
    P_values.append(P)
    print("Pressure [Pa]: ", format(P, '.3e'))
    start = int(input("Press 1 to Start: "))

plot(T_values,P_values)
xlabel("Temperature. [K]")
ylabel("Pressure. [Pa]")
grid()
show()
