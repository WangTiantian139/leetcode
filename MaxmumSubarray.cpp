/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/maximum-subarray
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int &numsback = nums.back();
        int maxsum = numsback;
        numsback = numsback > 0 ? numsback : 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int &numsi = nums[i];
            numsi += nums[i + 1];
            maxsum = maxsum >= numsi ? maxsum : numsi;
            if (numsi < 0) {
                numsi = 0;
            }
        }
        return maxsum;
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        istringstream istrm(argv[i]);
        int num;
        istrm >> num;
        nums.push_back(num);
    }
    for (auto &num: nums) {
        cout << num << " ";
    }
    cout << endl;
    int res = Solution().maxSubArray(nums);
    for (auto &num: nums) {
        cout << num << " ";
    }
    cout << endl;
    cout << res << endl;
}