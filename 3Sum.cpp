/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/3sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        this->sortNums(nums);
        // sort(nums.begin(), nums.end());
        vector<vector<int>> matsol;
        int lo = 0;
        int mi = lo + 1;
        int hi = nums.size() - 1;
        int sum3 = 0;
        while (lo < hi) {
            mi = lo + 1;
            while (mi < hi) {
                sum3 = nums[lo] + nums[mi] + nums[hi];
                if (sum3 == 0) {
                    matsol.push_back(vector<int>{nums[lo], nums[mi], nums[hi]});
                    for ( ; nums[mi] == nums[mi + 1]; mi++) {
                    }
                    mi++;
                } else if (sum3 < 0) {
                    mi++;
                } else if (sum3 > 0) {
                    hi--;
                } else { // undifined condition
                }
            }
            for ( ; nums[lo] == nums[lo + 1]; lo++) {
            }
            lo++;
            hi = nums.size() - 1;
        }
        return matsol;
    }
private:
    void sortNums(vector<int> &nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
            // cout << "nums during sorting: ";
            // for (int num: nums) {
            //     cout << num << " ";
            // }
            // cout << endl;
        }
        // cout << "sorted nums: ";
        // for (int num: nums) {
        //     cout << num << " ";
        // }
        // cout << endl;
    }
};

int main(int argc, char** argv) {
    ifstream ifstrm(argv[1]);
    if (!ifstrm) {
        cerr << "input file not open: " << string{argv[1]} << endl;
    }
    string line;
    vector<vector<int>> testmat;
    while (getline(ifstrm, line)) {
        // cout << line << endl;
        vector<int> nums;
        int num;
        istringstream isstrm(line);
        while (isstrm >> num) {
            nums.push_back(num);
        }
        testmat.push_back(nums);
    }
    int i = 0;
    for (auto &nums: testmat) {
        // print all nums in testmat
        cout << "example " << i++ << ": " << endl;
        for (int num: nums) {
            cout << num << " ";
        }
        cout << endl;

        auto sol = Solution().threeSum(nums);

        // print result
        for (auto &line: sol) {
            for (auto num: line) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

}