/*
 * node.cpp
 *
 *  Created on: 12-2013
 *      Author: Filip Nabrdalik
 */

#include "graph.h"
#include <stdlib.h>

#define MAX_CHARS 64

uint16_t getVerticesCount(char *filename)
{
	FILE *fp;
	uint16_t src_id = 0, dst_id = 0, weight;
	uint16_t v_count = 0;
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%d %d %d\n", &src_id, &dst_id, &weight) != EOF)
	{
		printf("Graph %d\n",src_id);
		if(src_id > v_count) v_count = src_id;
		else if(dst_id > v_count) v_count = dst_id;

			
	}
	fclose(fp);
	printf("Graph contains %u vertices\n", v_count);
	
	
	return v_count;
	
}

Graph* createGraph(char *filename)
{
	Graph  *g;
	FILE *fp;
	
	
	
	
	
	char line[MAX_CHARS];
	uint16_t src_id, dst_id, weight,i;
	uint16_t size;
	
	size = getVerticesCount(filename);
	g  = malloc( size * sizeof( struct t_Edge *));
	fp = fopen(filename, "r");
	
	for(i=0;i<size;i++)
	{
		g[i] = NULL ;
	}
	
	while ( fscanf(fp, "%d %d %d\n", &src_id, &dst_id, &weight) != EOF)
	{
		addEdge(g[src_id], dst_id, weight);
	}
	
	
	fclose(fp);  
	return g;
}

void addEdge(Graph g,uint16_t dst, uint16_t wght)
{
	struct t_Edge* tmp;
	
	tmp->dst_id=dst;
	tmp->weight=wght;
	tmp->next=NULL;
	
	if(g)
	{
		tmp->next =g;
		g = tmp;
	}
	else
	{
		g= tmp;
	
	}

}






