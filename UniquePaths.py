'''
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right


Example 2:

Input: m = 7, n = 3
Output: 28

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # if (m, n) == (1, 1):
        #     return 1
        # else:
        #     # return self.backtrace(m, n)
        #     memomat = [[-1 for col in range(n)] for row in range(m)]
        #     return self.backtrace_linearrecursive(m, n, memomat)
        return self.backtrace_dynamicprogramming(m, n)

    def backtrace(self, m: int, n: int):
        # print('call backtrace at point', m, n)
        npaths = 0

        if m - 1 == 1 and n == 1:
            npaths += 1
        elif m - 1 < 1:
            pass
        else:
            npaths += self.backtrace(m - 1, n)

        if m == 1 and n - 1 == 1:
            npaths += 1
        elif n - 1 < 1:
            pass
        else:
            npaths += self.backtrace(m, n - 1)

        # print(npaths, 'paths is found at point', m, n)
        return npaths

    def backtrace_linearrecursive(self, m: int, n: int, memomat):
        # print('call backtrace at point', m, n)
        npaths = 0

        if m - 1 == 1 and n == 1:
            npaths += 1
        elif m - 1 < 1:
            pass
        else:
            if memomat[m - 2][n - 1] != -1:
                npaths += memomat[m - 2][n - 1]
            else:
                npaths += self.backtrace_linearrecursive(m - 1, n, memomat)

        if m == 1 and n - 1 == 1:
            npaths += 1
        elif n - 1 < 1:
            pass
        else:
            if memomat[m - 1][n - 2] != -1:
                npaths += memomat[m - 1][n - 2]
            else:
                npaths += self.backtrace_linearrecursive(m, n - 1, memomat)

        memomat[m - 1][n - 1] = npaths
        # print(npaths, 'paths is found at point', m, n)
        # print(memomat)
        return npaths

    def backtrace_dynamicprogramming(self, m: int, n: int):
        i, j = m, n
        memomat = [[0 for col in range(n)] for row in range(m)]
        while i >= 1:
            j = n
            while j >= 1:
                if i == m or j == n:
                    memomat[i - 1][j - 1] = 1
                else:
                    memomat[i - 1][j - 1] = memomat[i][j - 1] + memomat[i - 1][j]
                # print(memomat, 'at', i, j)
                j -= 1
            i -= 1
        return memomat[0][0]

if __name__ == '__main__':
    testlist = (
        [1, 1],
        [2, 1],
        [3, 1],
        [1, 2],
        [1, 3],
        [2, 2],
        [3, 2],
        [7, 3],
    )
    for (m, n) in testlist:
        sol = Solution().uniquePaths(m, n)
        print(sol, 'at point', m, n)
    # m, n = 3, 2
    # sol = Solution().uniquePaths(m, n)
    # print(sol, 'at point', m, n)