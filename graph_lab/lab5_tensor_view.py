import numpy as np
import torch
import networkx as nx

l1=[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
t1=np.array(l1)
t1=torch.Tensor(t1)
print(f"t1.shape: {t1.shape}")
t1_pad=t1.view(6, -1)
print(f"t1_pad.shape: {t1_pad.shape}")