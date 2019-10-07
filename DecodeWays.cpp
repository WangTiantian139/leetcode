/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 *
 * Example 1:
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/decode-ways
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways(s.size() + 1, 1);
        if (s[s.size() - 1] == '0') {
            ways[s.size() - 1] = 0;
        } else
        {
            ways[s.size() - 1] = 1;
        }
        bool sing = 0;
        bool doub = 0;
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '0') {
                sing = 0;
            } else
            {
                sing = 1;
            }
            if (s[i] == '1') {
                doub = 1;
            } else if (s[i] == '2' && s[i + 1] <= '6' && s[i + 1] >= '0') {
                doub = 1;
            } else {
                doub = 0;
            }
            ways[i] = sing * ways[i + 1] + doub * ways[i + 2];
        }
        return ways[0];
    }
};

int main(int argc, char** argv) {
    vector<string> vecargv;
    for (int i = 1; i < argc; i++) {
        vecargv.push_back(string(argv[i]));
    }

    // for (const string &s: vecargv) {
    //     cout << s << endl;
    // }

    if (vecargv.empty()) {
        string s{"123"};
        auto res = Solution().numDecodings(s);
        cout << res << endl;
    } else if (vecargv[0] == "-f") {
        ifstream ifstrm(vecargv[1]);
        string s;
        Solution sol;
        while (getline(ifstrm, s)) {
            cout << s << " ";
            cout << sol.numDecodings(s) << endl;
        }
    } else {
    }
    return 0;
}