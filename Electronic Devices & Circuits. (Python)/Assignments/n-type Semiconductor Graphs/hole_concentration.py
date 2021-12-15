import matplotlib.pyplot as plt 
import numpy as np

ni = 1.90189E10                                                 #concentration of intrinsic silicon at room temperature. [carrier/cubic cm]
ND = [1E10, 2E10, 3E10, 4E10, 5E10, 6E10, 7E10, 8E10, 9E10]     #concentration of donor atom (Phosphorus). [carrier/cubic cm]
values = []
for x in ND:
    np = (ni**2)/(x + ni)                                       #concentration of holes in n-type doping. [carrier/cubic cm]
    values.append(np)
plt.plot(ND, values)
plt.title(r"$n_{p} = \frac{ n_{i}^{2} }{ N_{D} + n_{i} }$")
plt.xlabel('Concentration of the Donor atoms. [carrier/cubic cm]')  
plt.ylabel('Concentration of Holes. [carrier/cubic cm]')  
plt.legend() 
plt.savefig("Holes_Concentration.png")
plt.show()
