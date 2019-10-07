'''
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26


Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).


Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''

#%%
class Solution:
    def numDecodings(self, s: str) -> int:
        ways = [1 for i in range(len(s) + 1)]
        if s[len(s) - 1] == '0':
            ways[len(s) - 1] = 0
        else:
            ways[len(s) - 1] = 1

        for i in range(len(s) - 2, -1, -1):
            if s[i] == '0':
                sinflag = 0
            else:
                sinflag = 1
            if s[i] == '1':
                douflag = 1
            elif s[i] == '2' and s[i + 1] in '0123456':
                douflag = 1
            else:
                douflag = 0
            # print(sinflag, douflag)
            ways[i] = sinflag * ways[i + 1] + douflag * ways[i + 2]
        # print(ways)
        return ways[0]

#%%
if __name__ == "__main__":
    inputstr = '123'
    inputstr = '1111'
    inputstr = '11111'
    inputstr = '226'
    inputstr = '206'
    inputstr = '006'
    inputstr = '1006'
    inputstr = '110'
    print(inputstr)
    res = Solution().numDecodings(inputstr)
    print(res)


#%%
