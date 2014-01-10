#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdint.h>
#include <stdio.h>

struct t_Vertice{
	uint16_t dst_id; //vertice on the other side of the edge
    uint8_t  weight; //weight of the edge	
	struct t_Vertice *next;
};

typedef struct t_Vertice* Graph;

uint16_t getVerticesCount(char *filename);
Graph* createGraph(uint16_t size);
Graph* fillGraph(Graph* g, uint16_t size, char *filename);
void addVertice(Graph *g, uint16_t dst, uint16_t wght);
void showGraph(Graph* g, uint16_t size);

struct t_Edge{
	uint16_t src_id;
	uint16_t dst_id;
	uint8_t  weight;
};

struct tEdgeGraph{

	struct t_Edge* edges;
	uint16_t v_count;
	uint16_t e_count;
};

typedef struct tEdgeGraph EGraph;

uint16_t getEdgeCount(char *filename);
EGraph* createEGraph(uint16_t v_size,uint16_t e_size);
EGraph* fillEGraph(EGraph* g, char *filename);
void showEGraph(EGraph* eg, uint16_t size);




 




#endif /* GRAPH_H_ */

