import numpy as np
# import pickle
import networkx as nx
G = nx.path_graph(4)
print(G.edges())
print(G.nodes())
nx.add_path(G, [10, 11, 10,12])
nx.add_path(G, [3,10])
print(G.edges())
print(G.nodes())

CGs=[G.subgraph(c) for c in nx.connected_components(G)]
CGS=sorted(CGs, key=lambda x: x.number_of_nodes(), reverse=True)

# for i in range(len(CGs)):
#     print(f"CGs{[i]}.nodes() : {CGs[i].nodes()}")
#     print(f"CGs{[i]}.edges() : {CGs[i].edges()}")
node_list_bfs=[]
node_degree_list=[(n,d) for n , d in CGs[0].degree()]
print(f"node_degree_list: {node_degree_list}")
degree_sequence=sorted(node_degree_list, key=lambda tt: tt[1], reverse=True)
print(f"degree_sequence: {degree_sequence}")

dfs_tree=nx.dfs_tree(CGs[0], source=degree_sequence[0][0])
print(f"dfs_tree.nodes(): {dfs_tree.nodes()}")
print(f"dfs_tree.edges(): {dfs_tree.edges()}")
node_list_bfs+=list(dfs_tree.nodes())
print(f"node_list_bfs: {node_list_bfs}")