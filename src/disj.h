#ifndef DISJ_H_
#define DISJ_H_






/*Disjoint data set - struktura zbiorow rozlacznych*/

struct disj_set{
	int parent;
	int rnk;
};

 

int compareEdges(const void* edge_1, const void* edge_2);
int disj_find(struct disj_set* ssets, int vertice);



#endif /* DISJ_H_ */