/**
 * 给定 n 种物品和一个容量为 C 的背包，物品 i 的重量是 wi，其价值为 vi 。
 * 问：应该如何选择装入背包的物品，使得装入背包中的物品的总价值最大？
*/
#include <iostream>
#include <cstring>

int bag01(int *weight, int *value, int nitem, int capacity)
{
    int optmat[nitem + 1][capacity + 1];
    memset(optmat, 0, sizeof(optmat));

    for (int i = 1; i <= nitem; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j >= weight[i])
            {
                // chose the max value between optmat[i-1][j] and optmat[i-1][j-weight[i]]+value[i]
                optmat[i][j] = optmat[i - 1][j] < (optmat[i - 1][j - weight[i]] + value[i])
                    ? (optmat[i - 1][j - weight[i]] + value[i]) : optmat[i - 1][j];
            }
            else
            {
                optmat[i][j] = optmat[i - 1][j];
            }

        }
    }
    return optmat[nitem][capacity];
}

using namespace std;

int main()
{
    int nitem = 4;
    int weight[nitem + 1] = {0, 30, 20, 35, 40};
    int value[nitem + 1] = {0, 20, 18, 25, 30};
    int capacity = 50;
    // int nitem;
    // cin >> nitem;
    // int capacity;
    // int weight[nitem + 1] = {0};
    // int value[nitem + 1] = {0};
    // for (int i = 1; i <= nitem; i++)
    // {
    //     cin >> weight[i];
    // }
    // for (int i = 1; i <= nitem; i++)
    // {
    //     cin >> value[i];
    // }
    // cin >> capacity;
    int res = bag01(weight, value, nitem, capacity);
    cout << res << endl;

    return 0;
}