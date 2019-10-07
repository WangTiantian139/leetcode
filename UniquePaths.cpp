/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/unique-paths
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int memomat[m][n];
        memset(memomat, 0, sizeof(memomat));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    memomat[i][j] = 1;
                }
                else
                {
                    memomat[i][j] += memomat[i - 1][j] + memomat[i][j - 1];
                }
            }
        }
        return memomat[m - 1][n - 1];
    }
    void tryInitializing(std::ostream &os) {
        using namespace std;
        int m = 3;
        int n = 2;
        vector< vector<int> > memomat(m, vector<int>(n, 0));
        for (auto &line: memomat) {
            for (auto &elem: line) {
                os << elem;
            }
            os << endl;
        }
        os << endl;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    // sol.tryInitializing(std::cout);
    std::cout << argc << std::endl;
    // std::vector<std::string> argstrings;
    // for (int i = 0; i < argc; i++) {
    //     std::string s;
    //     int j = 0;
    //     while (argv[i][j] != '\0') {
    //         // std::cout << argv[i][j];
    //         // s += argv[i][j];
    //         j++;
    //     }
    //     // std::cout << std::endl;
    //     argstrings.push_back(s);
    // }

    // for (auto &s: argstrings) {
    //     std::cout << s << " ";
    // }
    // std::cout << std::endl;

    // initialize based on stringstream
    std::stringstream strm;
    std::vector<int> intargvs;
    for (int i = 0; i < argc; i++) {
        // std::string s{argv[i]};
        std::istringstream istrm(argv[i]);
        int inttemp = -1;
        istrm >> inttemp;           // input 0 into inttemp if a string of chars in istrm
        intargvs.push_back(inttemp);
    }
    for (auto &vals: intargvs) {
        std::cout << vals << " ";
    }
    std::cout << std::endl;


    return 0;
}