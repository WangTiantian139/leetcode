#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> res;
        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
            else if (numbers[i] + numbers[j] > target)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> numbers;
    int target;
    cout << "Input integer numbers, type -1 as the end:" << endl;
    int n = -1;
    while (true)
    {
        cin >> n;
        if (n > 0)
        {
            numbers.push_back(n);
        }
        else
        {
            break;
        }
    }
    cout << "Input an integer as targer:" << endl;
    cin >> target;
    vector<int> ans = solu.twoSum(numbers, target);
    cout << "ans is :" << endl;
    for (auto &a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}