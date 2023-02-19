import numpy as np
# import pickle
import networkx as nx

a=[]
a1=[1,2,3]
a2=[5,6,7]
a+=a1
print(a)
a+=a2
print(a)


n_feats=[[1,2],[2,3],[3,4],[5,6]]
n_feats=np.array(n_feats)
nodelist=[(1,2),(3,0),(0,3),(2,2)]
nodelist2=np.array(nodelist)
print(nodelist2[:,0])
featssss=n_feats[nodelist2[:,0]]
print(featssss)