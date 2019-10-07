'''
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"

'''


#%%
# inputstr = 'bbabad'
# inputstr = 'abbd'
# inputstr = 'abcbddbcba'
# inputstr = 'ac'
# inputstr = 'bbbbbbbb'
# inputstr = 'bbbbb'
# inputstr = 'ccc'
# inputstr = 'abcda'
inputstr = 'bbacdc'

#%%
def method1(s:str) -> str:
    #%%
    inputstr = s
    palin_substrs = []
    if len(inputstr) == 0:
        pass
    elif len(inputstr) == 1:
        palin_substrs.append(inputstr)
    elif len(inputstr) == 2:
        if inputstr[0] == inputstr[1]:
            palin_substrs.append(inputstr[0: 2])
        else:
            palin_substrs.append(inputstr[0])
    else:
        for i in range(0, len(inputstr) - 1):
            if i == 0:
                if inputstr[0] == inputstr[1]:
                    palin_substrs.append(inputstr[0: 2])
                else:
                    palin_substrs.append(inputstr[0])
            elif i > 0:
                i0, i1, i2 = i-1, i, i + 1
                if inputstr[i0] == inputstr[i2]:
                    j = 1
                    while j < 500 and i0 - j >= 0 and i2 + j < len(inputstr):
                        if inputstr[i0 - j] == inputstr[i2 + j]:
                            j += 1
                        else:
                            break
                    palin_substrs.append(inputstr[i0 - j + 1 : i2 + j])
                if inputstr[i1] == inputstr[i2]:
                    j = 1
                    while j < 500 and i1 - j >= 0 and i2 + j < len(inputstr):
                        if inputstr[i1 - j] == inputstr[i2 + j]:
                            j += 1
                        else:
                            break
                    palin_substrs.append(inputstr[i1 - j + 1 : i2 + j])

    #%%
    outputstr = ''
    maxlen = 0
    for substr in palin_substrs:
        if len(substr) > maxlen:
            outputstr = substr
            maxlen = len(substr)

    return outputstr

#%%
def method2(s:str) -> str:
    inputstr = s
    #%%
    imax_substr = -1
    maxlen = 0
    outputstr = ''
    if len(inputstr) == 0:
        pass
    elif len(inputstr) == 1:
        outputstr = inputstr
    elif len(inputstr) == 2:
        if inputstr[0] == inputstr[1]:
            outputstr = inputstr
        else:
            outputstr = inputstr[0]
    else:
        for i in range(0, len(inputstr) - 1):
            if i == 0:
                if inputstr[0] == inputstr[1]:
                    imax_substr = 0
                    maxlen = 2
                else:
                    outputstr = inputstr[0]
                    imax_substr = 0
                    maxlen = 1
            elif i > 0:
                i0, i1, i2 = i-1, i, i + 1
                if inputstr[i0] == inputstr[i2]:
                    j = 1
                    while j < 500 and i0 - j >= 0 and i2 + j < len(inputstr):
                        if inputstr[i0 - j] == inputstr[i2 + j]:
                            j += 1
                        else:
                            break
                    if i2 + j - (i0 - j + 1) > maxlen:
                        maxlen = i2 + j - (i0 - j + 1)
                        imax_substr = i0 - j + 1
                if inputstr[i1] == inputstr[i2]:
                    j = 1
                    while j < 500 and i1 - j >= 0 and i2 + j < len(inputstr):
                        if inputstr[i1 - j] == inputstr[i2 + j]:
                            j += 1
                        else:
                            break
                    if i2 + j - (i1 - j + 1) > maxlen:
                        maxlen = i2 + j - (i1 - j + 1)
                        imax_substr = i1 - j + 1
        outputstr = inputstr[imax_substr : imax_substr + maxlen]
    return outputstr


#%%
inputstrs = {
    'bbabad' : 'bab',
    'abbd' : 'bb',
    'abcbddbcba' : 'abcbddbcba',
    'ac' : 'a',
    'bbbbbbbb' : 'bbbbbbbb',
    'bbbbb' : 'bbbbb',
    'ccc' : 'ccc',
    'abcda' : 'a',
    'bbacdc' : 'cdc',
}
for s in inputstrs.keys():
    outputstr = method2(s)
    if outputstr == inputstrs[s]:
        pass
    else:
        print('{} is input while {} is output'.format(s, outputstr))

#%%
