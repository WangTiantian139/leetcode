"""
Given numberOfRadLiquid vectors (volume, mass, energy),
find the maximum sum energy of any ones among them, with
the constraints in volume and mass dimensions.
"""
#%%
class Item():
    def __init__(self, volume, mass, energy):
        self.volume = volume
        self.mass = mass
        self.energy = energy

#%%
reactorCap = 100
numberOfRadLiquid = 5
criticalMass = 15
volumes = [50, 40, 30, 20, 10]
masses = [1, 2, 3, 9, 5]
energies = [300, 480, 270, 200, 180]

item = [Item(0, 0, 0)]
for i in range(numberOfRadLiquid):
    item.append(
        Item(
            volume=volumes[i],
            mass=masses[i],
            energy=energies[i]
        )
    )

#%% constructure a 3d matrix,
#   x corresponding to item,
#   y corresponding to volume,
#   z corresponding to mass,
#   value corresponding to energy.
#   max numberOfRadLiquid is 30,
#   max reactorCap is 600,
#   max criticalMass is 200
emat = [[[0] * 201 for i in range(601)] for i in range(31)]

for x in range(1, numberOfRadLiquid + 1):
    for y in range(1, reactorCap + 1):
        for z in range(1, criticalMass + 1):
            if y >= item[x].volume and z >= item[x].mass:
                emat[x][y][z] = max([
                    emat[x - 1][y][z],
                    emat[x - 1][y - item[x].volume][z - item[x].mass] + item[x].energy
                ])
            else:
                emat[x][y][z] = emat[x - 1][y][z]
            # print(x, y, z, emat[x][y][z])
    print(x, y, z, emat[x][y][z])

print(emat[numberOfRadLiquid][reactorCap][criticalMass])

#%%
