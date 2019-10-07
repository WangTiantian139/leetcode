'''
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        return self.climbStairs3(n)

    def climbStairs1(self, nstep: int) -> int:
        if nstep == 1:
            return 1
        elif nstep == 2:
            return 2
        else:
            single_asend = self.climbStairs(nstep - 1)
            double_asend = self.climbStairs(nstep - 2)
            return single_asend + double_asend
    def climbStairs2(self, nstep: int) -> tuple:
        if nstep == 1:
            return 1, 1
        else:
            prev, Prevprev = self.climbStairs2(nstep - 1)
            return prev + Prevprev, prev
    def climbStairs3(self, nstep: int) -> int:
        prev, Prevprev = 1, 1
        for i in range(1, nstep):
            temp = prev
            prev = prev + Prevprev
            Prevprev = temp
        return prev


#%%
inputstr = '2'
nstep = eval(inputstr)

#%%
def climbStairs(nstep:int) -> int:
    if nstep == 1:
        return 1
    elif nstep == 2:
        return 2
    else:
        single_asend = climbStairs(nstep - 1)
        double_asend = climbStairs(nstep - 2)
        return single_asend + double_asend

#%%
def climbStairs2(nstep: int) -> tuple:
    if nstep == 1:
        return 1, 1
    else:
        prev, Prevprev = climbStairs2(nstep - 1)
        return prev + Prevprev, prev


#%%
def climbStairs3(nstep: int) -> int:
    prev, Prevprev = 1, 1
    for i in range(1, nstep):
        temp = prev
        prev = prev + Prevprev
        Prevprev = temp
    return prev

#%%
