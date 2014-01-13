import matplotlib.pyplot as plt
import networkx as nx
G=nx.Graph()
G=nx.connected_watts_strogatz_graph(60, 20, 0.1, tries=100, seed=None)


print G.number_of_nodes(), G.number_of_edges(), nx.is_connected(G)
nx.draw(G)
#plt.show()
nx.write_weighted_edgelist(G,"out.txt")

