#%%
class RadLiquid():
    def __init__(self, volume, mass, energy):
        self.volume = volume
        self.mass = mass
        self.energy = energy

def Add(rl1: RadLiquid, rl2: RadLiquid) -> RadLiquid:
    return RadLiquid(
        volume=rl1.volume + rl2.volume,
        energy=rl1.energy + rl2.energy,
        mass=rl1.mass + rl2.mass
        )

#%%
