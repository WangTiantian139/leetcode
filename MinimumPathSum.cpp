/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/minimum-path-sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        for (int i = nrow - 1; i >= 0; i--) {
            for (int j = ncol - 1; j >= 0; j--) {
                if (i == nrow - 1 && j == ncol - 1) {
                } else if (i == nrow - 1 && j != ncol - 1) {
                    grid[i][j] += grid[i][j + 1];
                } else if (i != nrow - 1 && j == ncol - 1) {
                    grid[i][j] += grid[i + 1][j];
                } else {
                    grid[i][j] += min(grid[i][j + 1], grid[i + 1][j]);
                }
            }
        }
        return grid[0][0];
    }
};

int main(int argn, char** argv)
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int res = Solution().minPathSum(grid);
    cout << res << endl;

    return 0;
}
