import matplotlib.pyplot as plt 

ND = [1E10, 2E10, 3E10, 4E10, 5E10, 6E10, 7E10, 8E10, 9E10]   #concentration of donor atom (Phosphorus). [carrier/cubic cm]
final_ND = []
ni = 1.90189E10                                               #concentration of intrinsic silicon at room temperature. [carrier/cubic cm]
for each in ND:
    s = each + ni                                             #concentration of electron in n-type doping. [carrier/cubic cm]
    final_ND.append(s)
nn = final_ND
plt.title(r"$n_{n} = n_{i} + N_{D}$")
plt.xlabel('Concentration of the Donor atoms. [carrier/cubic cm]')  
plt.ylabel('Concentration of Electrons. [carrier/cubic cm]') 
plt.plot(ND, nn)   
plt.savefig("Electron_Concentration.png")
plt.legend()
plt.show()
