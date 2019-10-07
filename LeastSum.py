# length, nsum = input().split(' ')
# nums = input().split(' ')
#%%
inputstr = ('7 3', '1 2 6 1 1 7 1')
length, nsum = inputstr[0].split(' ')
nums = inputstr[1].split(' ')
length, nsum = eval(length), eval(nsum)
for idx in range(0, length):
    nums[idx] = eval(nums[idx])


#%%
qnum = nums[0: nsum]
sum = 0
minsum = 0
imin = 0
for num in qnum:
    sum = sum + num
minsum = sum

#%%
for idx in range(1, length - nsum + 1):
    num = nums[idx + nsum - 1]
    head = qnum.pop(0)
    qnum.append(num)
    print(idx, qnum, head, num)
    sum = sum + num - head
    print(sum)
    if sum < minsum:
        minsum = sum
        imin = idx




#%%
print(imin, minsum)

#%%
