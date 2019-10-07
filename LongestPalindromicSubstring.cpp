/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 *Example 1:
 *
 *Input: "babad"
 *Output: "bab"
 *Note: "aba" is also a valid answer.
 *
 *
 *Example 2:
 *
 *Input: "cbbd"
 *Output: "bb"
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/longest-palindromic-substring
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s);
private:
    // return -1 for not center; 0 for even center; 1 for odd center
    int isCenter(const string &s, int i);
    int expandPalindrome(const string &s, int i, int centertype);
};

string Solution::longestPalindrome(string s) {
    int slen = s.length();
    int istart= 0;
    int maxlen = 1;
    for (int i = 0; i < slen; i++) {
        int plen = 0;
        int explen = 0;
        int explen1 = 0;
        int ist = 0;
        switch (isCenter(s, i))
        {
        case -1:
            break;
        case 0:
            explen = expandPalindrome(s, i, 0);
            ist = i - explen;
            plen = 2 * explen + 2;
            break;
        case 1:
            explen = expandPalindrome(s, i, 1);
            ist = i - explen - 1;
            plen = 2 * explen + 3;
            break;
        case 2:
            explen = expandPalindrome(s, i, 0);
            explen1 = expandPalindrome(s, i, 1);
            if (explen > explen1) {
                ist = i - explen;
                plen = 2 * explen + 2;
            } else
            {
                ist = i - explen1 - 1;
                plen = 2 * explen1 + 3;
            }
        default:
            break;
        }
        if (maxlen < plen) {
            maxlen = plen;
            istart = ist;
        }
        // cout << "case i = " << i << "\t"
        //      << "explen = " << explen << ", ist = " << ist << ", plen = " << plen << endl;
    }
    // cout << "istart = " << istart << ", maxlen = " << maxlen << endl;
    return s.substr(istart, maxlen);
}

// return -1 for not center; 0 for even center; 1 for odd center; 2 for both
int Solution::isCenter(const string &s, int i) {
    if (s[i] == s[i + 1] && i != 0 && s[i - 1] == s[i + 1]) {
        return 2;
    }
    else if (i != 0 && s[i - 1] == s[i + 1]) {
        return 1;
    } else if (s[i] == s[i + 1]) {
        return 0;
    } else {
        return -1;
    }
}

// centertype = 0 for even center; 1 for odd center;
int Solution::expandPalindrome(const string &s, int i, int centertype) {
    int explen = 1;
    while (i - explen - centertype >= 0 && s[i - explen - centertype] == s[i + 1 + explen])
    {
        explen++;
    }
    return explen - 1;
}

int main(int argc, char** argv) {
    Solution sol;
    // vector<string> strargvs{"aba", "babad", "a", "bb", "abcd", "bbb", "aaaa"};
    vector<string> strargvs;
    for (int i = 1; i < argc; i++) {
        string s{argv[i]};
        strargvs.push_back(s);
    }
    // for (string &s: strargvs) {
    //     cout << s << " ";
    // }
    for (string s: strargvs) {
        cout << s << " ";
        auto res = sol.longestPalindrome(s);
        cout << res << " " << endl;
    }
    // string s("babad");
    // string s("cbbd");
    // auto res = sol.longestPalindrome(s);
    // cout << s << " " << res << " ";
    cout << endl;
    return 0;
}