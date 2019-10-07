'''
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
#%%
nums = [0, 1, 2]
nums = [-3, -2, -1, 0, 1, 2, 3]
nums = [-1, -1, -1, 0, 0, 0, 1]
nums = [0, 0, 0, 0, 0]
nums = [-1, 0, 1, 2, -1, -4]
nums.sort()

#%%
print(nums)

#%%
sollist = []
ilo = 0
ihi = len(nums) - 1
while ilo < ihi:
    imi = ilo + 1
    while imi < ihi:
        sum3 = nums[ilo] + nums[ihi] + nums[imi]
        if sum3 == 0: # meet the condition, quit this loop and move ilo
            if [nums[ilo], nums[imi], nums[ihi]] not in sollist:
                sollist.append([nums[ilo], nums[imi], nums[ihi]])
            imi += 1
        elif sum3 < 0:
            imi += 1
        elif sum3 > 0:
            ihi -= 1
    ilo += 1
    ihi = len(nums) - 1


#%%
print(sollist)

#%%
class Solution:
    def threeSum(self, nums):
        nums.sort()
        sollist = []
        ilo = 0
        ihi = len(nums) - 1
        while ilo < ihi:
            imi = ilo + 1
            while imi < ihi:
                sum3 = nums[ilo] + nums[ihi] + nums[imi]
                if sum3 == 0: # meet the condition, quit this loop and move ilo
                    sollist.append([nums[ilo], nums[imi], nums[ihi]])
                    while nums[imi] == nums[imi + 1] and imi + 1 < ihi:
                        imi += 1
                    imi += 1
                elif sum3 < 0:
                    imi += 1
                elif sum3 > 0:
                    ihi -= 1
            while nums[ilo] == nums[ilo + 1] and ilo < len(nums) - 2:
                ilo += 1
            ilo += 1
            ihi = len(nums) - 1
        return sollist

nums = [0, 1, 2]
nums = [-3, -2, -1, 0, 1, 2, 3]
nums = [-1, -1, -1, 0, 0, 0, 1]
nums = [0, 0, 0, 0, 0]
nums = [-1, 0, 1, 2, -1, -4]
print(nums)
sollist = Solution().threeSum(nums)
print(sollist)

#%%
