'''
Assume n mountains is to be climbed as mountain 1, 2, ... , n.
There are unidirectional bridges between some mountains,
express as 12, which means a bridge from mountain 1 to mountain 2.
Find the least time to climb all of the n mountains.
Example 1:
Input:
5
12, 13, 24, 25, 35
Output:
2
Explanation:
route: 0->1->2->4->0->3->5 or 0->1->3->5->0->2->4
         0 as ground
'''
#%% input
nmountain = 5
bridges = (
    '12',
    '13',
    '24',
    '25',
    '35',
)

#%% neighbormat row-col:head-tail
neighbormat = [[0] * nmountain for row in range(nmountain)]
for bridge in bridges:
    head = eval(bridge[0]) - 1
    tail = eval(bridge[1]) - 1
    neighbormat[head][tail] = 1

#%% Graph-related definition
class STATUSLIST:
    UNDISCOVERED = 0
    DISCOVERED = 1
    VISITED = 2

class EDGETYPELIST:
    UNDETERMINED = 0
    TREE = 1
    CROSS = 2
    FORWARD = 3
    BACKWARD = 4

class Vertex():
    indegree = 0
    outdegree = 0
    status = STATUSLIST.UNDISCOVERED
    dtime = 0   # discovering time
    ftime = 0   # finishing discovering time
    parent = -1
    priority = 'INT_MAX'
    def __init__(self, data=0):
        self.data = data

class Edge():
    etype = EDGETYPELIST.UNDETERMINED
    def __init__(self, weight, data=0):
        self.data = data
        self.weight = weight

#%%
class GraphMat():
    def __init__(self, neighbormat):
        self.edgemat = []
        self.vertexlist = []
        self.nrow = len(neighbormat)
        self.ncol = len(neighbormat[0])
        for row in range(len(neighbormat)):
            edgerow = []
            self.vertexlist.append(Vertex())
            for col in range(len(neighbormat[0])):
                weight = neighbormat[row][col]
                edgerow.append(Edge(weight))
            self.edgemat.append(edgerow)
        self.__update_indegree(neighbormat)
        self.__update_outdegree(neighbormat)

    def __update_indegree(self, neighbormat):
        for col in range(len(neighbormat[0])):
            indegree = 0
            for row in range(len(neighbormat)):
                if neighbormat[row][col] == 1:
                    indegree += 1
            self.vertexlist[col].indegree = indegree

    def __update_outdegree(self, neighbormat):
        for row in range(len(neighbormat)):
            outdegree = 0
            for col in range(len(neighbormat[0])):
                if neighbormat[row][col] == 1:
                    outdegree += 1
            self.vertexlist[row].outdegree = outdegree

    # return whether edge (row, col) is exist(weight > 0)
    def exist(self, row: int, col: int) -> bool:
        if row < self.nrow and col < self.ncol and self.edgemat[row][col].weight > 0:
            return True
        else:
            return False


#%% DFS tree
rootver = 0
discovered_stack = []
graphmat = GraphMat(neighbormat)

iver = rootver % nmountain
# the vertex is undiscovered
if graphmat.vertexlist[iver].status == STATUSLIST.UNDISCOVERED:
    graphmat.vertexlist[iver].status = STATUSLIST.DISCOVERED
    discovered_stack.append(iver)


#%% DFS forest
