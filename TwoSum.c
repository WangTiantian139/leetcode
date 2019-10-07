#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices{-1, -1};
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (target == nums[i] + nums[j])
                {
                    indices[0] = i;
                    indices[1] = j;
                    break;
                }
            }
            if (indices[0] != -1)
            {
                break;
            }
        }
        return indices;
    }
};