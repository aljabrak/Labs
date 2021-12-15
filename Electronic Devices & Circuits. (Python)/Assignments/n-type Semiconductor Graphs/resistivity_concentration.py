import matplotlib.pyplot as plt 
import numpy as np

q = 1.6E-19                                                    #charge of electron.
ni = 1.90189E10                                                #concentration of intrinsic silicon at room temperature. [carrier/cubic cm]
up = 480                                                       #holes mobility.    [square cm/V.s]
un = 1350                                                      #electron mobility. [square cm/V.s]
ND = [1E15, 2E15, 3E15, 4E15, 5E15, 6E15, 7E15, 8E15, 9E15]    #concentration of donor atom (Phosphorus). [carrier/cubic cm]
values=[]
for x in ND:
    p = (x + ni)/(q*((un*x**2) + (un*ni*x) + (up*ni**2)))      #'p' is resistivity of n-type doped semiconductor. [ohm.cm]
    values.append(p)
plt.plot(ND, values)
plt.title(r"$\rho = \frac{ N_{D} + n_{i} }{q \left( u_{n} \cdot N_{D}^{2} + u_{n} \cdot n_{i} \cdot N_{d} + u_{p} \cdot n_{i}^{2} \right) }$")
plt.xlabel('Concentration of the Donor atoms. [carrier/cubic cm]')  
plt.ylabel('Resistivity of Silicon. [ohm.cm]') 
plt.legend() 
plt.savefig("Restivity_Concentration.png")
plt.show()
