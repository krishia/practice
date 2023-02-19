import numpy as np
import networkx as nx
import pygsp 


g_temp=nx.grid_2d_graph(5,7)
print(f"g_temp.nodes: {g_temp.nodes()})")
# graphs=[]
# for i in range(10,20):
#     for j in range(10,20):
#         graphs.append(G=nx.grid_2d_graph(i,j))

nodes={n:i for i, n in enumerate(g_temp.nodes, start=1)}
print(f"indexed nodes : {nodes}")

# G_temp2=pygsp.graphs.ErdosRenyi()
# G_temp2.set_coordinates()
# G_temp2.plot()
# G_temp3=pygsp.graphs.Grid2d(N1=5, N2=7)
# G_temp3.plot()