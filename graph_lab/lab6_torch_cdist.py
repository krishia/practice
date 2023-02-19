import numpy as np
import torch
import networkx as nx

a = torch.tensor([[0.9041,  0.0196], [-0.3108, -2.4423], [-0.4821,  1.059]])
b = torch.tensor([[-2.1763, -0.4713], [-0.6986,  1.3702]])
print(f"torch.cdist(a, b, p=2): {torch.cdist(a, b, p=2)}")
print(f"torch.cdist(a, b): {torch.cdist(a, b)}")

c=torch.tensor([3., 4.])
d=torch.tensor([1.,1.])
print(f"torch.dist(c, d, p=2): {torch.dist(c, d, p=2)}")
print(f"torch.dist(c, d): {torch.dist(c, d)}")