import numpy as np
# import pickle
import networkx as nx
# with open("out_feats.pickle", "rb") as fr:
#     data=pickle.load(fr)

# print(data)
# t1=[[1,2,3],[4,5,6]]

# t2=[[7,8,9],[10,11,12]]

# t3=t2[t1]
# print(t3)

G = nx.complete_graph(4)
G1 = nx.DiGraph()
G2 = nx.Graph()

G1.add_node(1)
G1.add_node(2)
G1.add_edge(1,2)

G2.add_node(1)
G2.add_node(2)
G2.add_edge(1,2)

T = nx.dfs_tree(G, source=0)

T1 = nx.dfs_tree(G1)
T2 = nx.dfs_tree(G2)

print("T1 ", T1.nodes())
print("T2 ", T2.nodes())

print(T.edges())
nT=list(T.nodes())
print(nT)


