#%%
import numpy as np

#%%
matA, n, symbol  = [], 3, 'a'
for i in range(n):
    row = []
    for j in range(n):
        row.append(symbol + str(i + 1) + str(j + 1))
    matA.append(row)
matA = np.array(matA)

#%%
veca = np.array(['a1', 'a2', 'a3']).reshape(1, 3)
vecb = np.array(['b1', 'b2', 'b3']).reshape(3, 1)

#%%
vecres = np.zeros([veca.shape[0], vecb.shape[1]], dtype='<U200')
for i in range(veca.shape[0]):
    for j in range(vecb.shape[1]):
        res = ''
        for k in range(veca.shape[1]):
            res += veca[i, k] + vecb[k, j] + '+'
        vecres[i,j] = res[:-1]
print(vecres)

#%%
def matrix(symbol, nrow, ncol, rowsym='none', colsym='none') -> np.ndarray:
    mat = []
    for i in range(nrow):
        row = []
        for j in range(ncol):
            if rowsym == 'none' and colsym == 'none':
                row.append(symbol + str(i + 1) + str(j + 1))
            elif rowsym != 'none' and colsym == 'none':
                row.append(symbol + rowsym + str(j + 1))
            elif rowsym == 'none' and colsym != 'none':
                row.append(symbol + str(i + 1) + colsym)
            else:
                print('rowsym and colsym cannot be defined at the same time')
        mat.append(row)
    return np.array(mat, dtype='<U200')

#%%
def matproduct(matA: np.ndarray, matB: np.ndarray) -> np.ndarray:
    matR = np.zeros([matA.shape[0], matB.shape[1]], dtype='<U200')
    for i in range(matA.shape[0]):
        for j in range(matB.shape[1]):
            rowR = ''
            for k in range(matA.shape[1]):
                itemA, itemB = matA[i, k], matB[k, j]
                if '+' in itemA:
                    itemA = '({})'.format(itemA)
                if '+' in itemB:
                    itemB = '({})'.format(itemB)
                rowR += itemA + itemB + '+'
            matR[i,j] = rowR[:-1]
    return matR

#%%
vecci = matrix('c', 3, 1, colsym='i')
vecx = matrix('x', 1, 3, rowsym='')
veccj = matrix('c', 3, 1, colsym='j')

#%%
matcix = matproduct(vecci, vecx)
print(matcix)

matxcix = matproduct(vecx, matcix)
print(matcix)

#%% TODO add () when + in item of matrices
matxcixcj = matproduct(matxcix, veccj)
print(matxcixcj)

#%%
matC = matrix('c', 3, 3)
matA = matrix('a', 3, 3)

#%%
matCTA = matproduct(matC.transpose(), matA)
print(matCTA)

#%%
matCTAC = matproduct(matCTA, matC)
print(matCTAC)

#%%
