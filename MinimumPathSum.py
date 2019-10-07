'''
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''

class Solution:
    def minPathSum(self, grid: list) -> int:
        nrow, ncol = len(grid), len(grid[0])
        minsumgrid = [[0 for i in range(ncol)] for j in range(nrow)]
        for row in range(nrow - 1, -1, -1):
            for col in range(ncol - 1, -1, -1):
                if row == nrow - 1 and col == ncol - 1:
                    minsumgrid[row][col] = grid[row][col]
                elif row == nrow - 1 and col != ncol - 1:
                    minsumgrid[row][col] = grid[row][col] + minsumgrid[row][col + 1]
                elif row != nrow - 1 and col == ncol - 1:
                    minsumgrid[row][col] = grid[row][col] + minsumgrid[row + 1][col]
                elif row < nrow - 1 and col < ncol - 1:
                    minsumgrid[row][col] = grid[row][col] + min(minsumgrid[row + 1][col], minsumgrid[row][col + 1])
                else:
                    print('unexpected case occured')

        return minsumgrid[0][0]


if __name__ == '__main__':
    # inputlist = [
    #     [1,3,1],
    #     [1,5,1],
    #     [4,2,1]
    # ]
    inputlist = [
        [1,0,0],
        [1,0,0],
        [4,0,0]
    ]
    inputlist = [
        [1,0,0],
        [1,1,1],
        [4,0,0]
    ]
    inputlist = [
        [1]
    ]
    res = Solution().minPathSum(inputlist)
    print(res)