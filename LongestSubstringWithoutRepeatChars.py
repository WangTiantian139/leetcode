'''
Given a string, find the length of the longest substring 
without repeating characters.

Example 1:
    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3. 
Example 2:
    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
Example 3:
    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3. 

**Note** that the answer must be a substring, "pwke" is a 
subsequence and not a substring.
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ptr_substart = 0
        ptr_subend = 1
        ans = 0
        while ptr_subend < len(s):
            i = ptr_subend - 1
            while i >= ptr_substart:
                if s[i] == s[ptr_subend]:
                    # lst_ndiffchars.append(ptr_subend - ptr_substart)
                    if ans < ptr_subend - ptr_substart : 
                        ans = ptr_subend - ptr_substart
                    ptr_substart = i + 1
                    break
                else:
                    i -= 1
            ptr_subend += 1
        # lst_ndiffchars.append(len(s) - ptr_substart)
        if ans < len(s) - ptr_substart : 
            ans = len(s) - ptr_substart

        # ans = max(lst_ndiffchars)
        return ans
    
#%%

# s = 'abcabcbb'
# s = '123456'
s = '11111'
s = "pwwkew"
s = " "
s = 'dvadbvf'
s = ''

ans = 1

#%%

ptr_substart = 0
ptr_subend = 1
lst_ndiffchars = []
ans = 0
while ptr_subend < len(s):
    i = ptr_subend - 1
    while i >= ptr_substart:
        if s[i] == s[ptr_subend]:
            # lst_ndiffchars.append(ptr_subend - ptr_substart)
            if ans < ptr_subend - ptr_substart : 
                ans = ptr_subend - ptr_substart
            ptr_substart = i + 1
            break
        else:
            i -= 1
    ptr_subend += 1
# lst_ndiffchars.append(len(s) - ptr_substart)
if ans < len(s) - ptr_substart : 
    ans = len(s) - ptr_substart

# ans = max(lst_ndiffchars)
print(ans)