/*
 *   Given a string, find the length of the longest sub-string 
 *   without repeating characters.
 *
 *   Example 1:
 *       Input: "abcabcbb"
 *       Output: 3 
 *       Explanation: The answer is "abc", with the length of 3. 
 *   Example 2:
 *       Input: "bbbbb"
 *       Output: 1
 *       Explanation: The answer is "b", with the length of 1.
 *   Example 3:
 *       Input: "pwwkew"
 *       Output: 3
 *       Explanation: The answer is "wke", with the length of 3. 
 *
 *   **Note** that the answer must be a substring, "pwke" is a 
 *   subsequence and not a substring.
*/


#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int ndiffchars = 0;
        for (; end < s.length(); end++)
        {
            for (int i = end - 1; i >= start; i--)
            {
                if (s[i] == s[end])
                {
                    if (ndiffchars < end - start)
                    {
                        ndiffchars = end - start;
                    }
                    start = i + 1;
                    break;
                }
            }
        }

        if (ndiffchars < s.length() - start)
        {
            ndiffchars = s.length() - start;
        }
        return ndiffchars;
    }

};