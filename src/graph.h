#ifndef GRAPH_H_
#define GRAPH_H_


#include <stdio.h>

struct t_Vertice{
	int dst_id; //vertice on the other side of the edge
    int  weight; //weight of the edge	
	struct t_Vertice *next;
};

typedef struct t_Vertice* Graph;

int getVerticesCount(char *filename);
Graph* createGraph(int size);
Graph* fillGraph(Graph* g, int size, char *filename);
void addVertice(Graph *g, int dst, int wght);
void showGraph(Graph* g, int size);

struct t_Edge{
	int src_id;
	int dst_id;
	int  weight;
};

struct tEdgeGraph{

	struct t_Edge* edges;
	int v_count;
	int e_count;
};

typedef struct tEdgeGraph EGraph;

int getEdgeCount(char *filename);
EGraph* createEGraph(int v_size,int e_size);
EGraph* fillEGraph(EGraph* g, char *filename);
void showEGraph(EGraph* eg, int size);




 




#endif /* GRAPH_H_ */

