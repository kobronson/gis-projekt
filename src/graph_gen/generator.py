import matplotlib.pyplot as plt
import networkx as nx
import random;
import os
G=nx.Graph()
v_gen = [100, 200, 500]
p_gen =  [0.1,0.3,0.5,0.7,0.9]



filelist = [ f for f in os.listdir(".") if f.endswith(".txt") ]
for f in filelist:
    os.remove(f)



for v in v_gen:
	for p in p_gen:
		G=nx.erdos_renyi_graph(v,p)#G=nx.connected_watts_strogatz_graph(v, v/2, p, tries=100, seed=None)
		print v, p,G.number_of_nodes(), G.number_of_edges(), nx.is_connected(G)
		
		for a,c,d in G.edges(data=True):
			d['weight']=random.randint(1, 254)
		filename = "er_"+ str(v)+"_"+str(p)+".txt"
		nx.write_weighted_edgelist(G,filename)

# nx.draw(G)
# #plt.show()


