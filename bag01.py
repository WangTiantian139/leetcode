# #%%
# import numpy as np

# #%%
# num = len(weight)
# bag2 = np.zeros((num+1,weight_most+1),dtype=np.int32)#下标从零开始


#%%
weight = [4,3,10,12,5]
value = [3,9,8,16,20]
weight_most = 20

#%%
def bag_0_1(weight, value, weight_most):  # return max value
    num = len(weight)
    weight.insert(0, 0)  # 前0件要用
    value.insert(0, 0)  # 前0件要用
    bag = [[0] * (weight_most + 1) for i in range(num + 1)]
    for i in range(1, num+1):
        for j in range(1, weight_most+1):
            if weight[i] <= j:
                bag[i][j] = max(bag[i-1][j-weight[i]]+value[i], bag[i-1][j])
            else:
                bag[i][j] = bag[i-1][j]
    # print(bag)
    return bag[-1][-1]

#%%
result = bag_0_1(weight, value, weight_most)
print(result)


#%%
