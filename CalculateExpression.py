#%%
# strexp = input()
strexp = '1&(1|0&1)'

#%%

NUMLIST = ['0', '1']
EXPLIST = {'&':0, '|':1, '!':2, '(':3, ')':4}
PRILIST = [ # 优先级 [栈顶] [当前]
    #   &   |   !   (   )   \0  #
    [   '>','>','<','<','>','<'],   # &
    [   '>','>','<','<','>','<'],   # |
    [   '>','>','>','', '>','<'],   # !
    [   '<','<','<','<','=','<'],   # (
    [   '', '', '', '', '' ,'<']   # (
]

#%%
expstack = []
numstack = []
strexp += '\0'
for char in strexp:
    if char in NUMLIST:
        numstack.append(char)
    elif char in EXPLIST.keys():
        if len(expstack) == 0:
            expstack.append(char)
        else:
            top = expstack[-1]
            # print(EXPLIST[top], EXPLIST[char])
            order = PRILIST[EXPLIST[top]][EXPLIST[char]]
            if order == '<':
                expstack.append(char)
            elif order == '=':
                expstack.pop()
            elif order == '>':
                exp = expstack.pop()
                # print(exp)
                if exp == '!':
                    num = numstack.pop()
                    if num == '0':
                        numstack.append('1')
                    else:
                        numstack.append('0')
                else:
                    # print(char, numstack)
                    num2 = numstack.pop()
                    num1 = numstack.pop()
                    numstack.append(eval(num1 + exp + num2))
                    # print(numstack)
    else:
        pass
    print(expstack, numstack)

#%%
print(numstack.pop())

#%%
