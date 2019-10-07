/**
 * Given numberOfRadLiquid vectors (volume, mass, energy),
 * find the maximum sum energy of any ones among them, with
 * the constraints in volume and mass dimensions.
*/
#include <iostream>
#include <cstring>
#include <vector>

class Item
{
private:
    int _volume;
    int _mass;
    int _energy;
public:
    Item(int volume, int mass, int energy):
    _volume(volume), _mass(mass), _energy(energy) {}
    ~Item() = default;
    int& volume()
    {
        return this->_volume;
    }
    int& mass()
    {
        return this->_mass;
    }
    int& energy()
    {
        return this->_energy;
    }
    void reset(int volume, int mass, int energy)
    {
        this->_volume = volume;
        this->_mass = mass;
        this->_energy = energy;
    }
};

using namespace std;

int bag01with2constraints(int *volumes, int *masses, int *energies,
    int numberOfRadLiquid, int reactorCap, int criticalMass)
{
    vector<Item> item(numberOfRadLiquid + 1, Item(0, 0, 0));
    for (int i = 1; i <= numberOfRadLiquid; i++)
    {
        item[i].reset(
            volumes[i - 1],
            masses[i - 1],
            energies[i - 1]
        );
    }
    // for (auto &i: item)
    // {
    //     printf("(v, m, e) = (%d, %d, %d)\n", i.volume(), i.mass(), i.energy());
    // }

    int emat[numberOfRadLiquid + 1][reactorCap + 1][criticalMass + 1];
    int x, y, z;
    for (x = 1; x <= numberOfRadLiquid; x++)
    {
        for (y = 1; y <= reactorCap; y++)
        {
            for (z = 1; z <= criticalMass; z++)
            {
                if (y >= item[x].volume() && z >= item[x].mass())
                {
                    emat[x][y][z] =
                        max(
                            emat[x - 1][y][z],
                            emat[x - 1][y - item[x].volume()][z - item[x].mass()] + item[x].energy()
                        );
                }
                else
                {
                    emat[x][y][z] = emat[x - 1][y][z];
                }
            }
            // printf("x=%d, y=%d, z=%d, e=%d\n", x, y - 1, z - 1, emat[x][y - 1][z - 1]);
        }
        // printf("x=%d, y=%d, z=%d, e=%d\n", x, y - 1, z - 1, emat[x][y - 1][z - 1]);
    }
    return emat[numberOfRadLiquid][reactorCap][criticalMass];
}

int main()
{
    int reactorCap = 100;
    int numberOfRadLiquid = 5;
    int criticalMass = 15;
    int volumes[] = {50, 40, 30, 20, 10};
    int masses[] = {1, 2, 3, 9, 5};
    int energies[] = {300, 480, 270, 200, 180};

    int res = bag01with2constraints(volumes, masses, energies, numberOfRadLiquid, reactorCap, criticalMass);
    printf("%d", res);
}