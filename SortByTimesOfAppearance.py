#%%
inputnum = input()
inputsalaries = input()
# inputnum = 'num = 19'
# inputsalaries = 'salaries=[1,2,4,3,3,3,4,2,5,5,5,5,6,6,6,7,8,9,10'

#%%
num = eval(inputnum.split(' ')[-1])
salariesstr = inputsalaries.split('=')[-1]
salariesstr = salariesstr.replace('[', '').replace(']', '').split(',')
salaries = []
for sal in salariesstr:
    salaries.append(eval(sal))

#%%
salstack = []
saltimes = {}
for sal in salaries:
    if sal not in salstack:
        salstack.append(sal)
        saltimes[sal] = 1
    else:
        saltimes[sal] += 1

for j in range(len(salstack)):
    for i in range(1, len(salstack)):
        if saltimes[salstack[i - 1]] < saltimes[salstack[i]]:
            print(salstack[i - 1], saltimes[salstack[i - 1]], salstack[i], saltimes[salstack[i]])

            temp = salstack[i - 1]
            salstack[i - 1] = salstack[i]
            salstack[i] = temp
        else:
            pass

#%%
output = ''
outputlist = []
for sal in salstack:
    time = saltimes[sal]
    for i in range(time):
        outputlist.append(str(sal))

output = '[' + ','.join(outputlist) + ']'

#%%
print(output)

#%%
