#ifndef GRAPH_H_
#define GRAPH_H_


#include <stdio.h>

/*Reprezentacja w postaci listy sąsiedztwa*/
struct t_Vertice{
	int dst_id;
    int  weight; 
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

/*Reprezentacja krawedziowa*/


struct tEdgeGraph{

	struct t_Edge* edges;
	int v_count;
	long int e_count;
};

typedef struct tEdgeGraph EGraph;

int getEdgeCount(char *filename);
EGraph* createEGraph(int v_size,long int e_size);
EGraph* fillEGraph(EGraph* g, char *filename);
void showEGraph(EGraph* eg, long int size);




 




#endif /* GRAPH_H_ */

