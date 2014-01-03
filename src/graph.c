/*
 * node.cpp
 *
 *  Created on: 12-2013
 *      Author: Filip Nabrdalik
 */

#include "graph.h"
#include "debug.h"
#include <stdlib.h>
#include <inttypes.h>

#define MAX_CHARS 64




uint16_t getVerticesCount(char *filename)
{
	FILE *fp;
	uint16_t src_id = 0, dst_id = 0, weight;
	uint16_t v_count = 0;
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%" SCNu16 "%" SCNu16 "%" SCNu16 "\n", &src_id, &dst_id, &weight) != EOF)
	{
		if(src_id > v_count) v_count = src_id;
		if(dst_id > v_count) v_count = dst_id;			
	}
	fclose(fp);
	printf("Graph contains %d vertices\n", v_count);
	
	
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
	
	while ( fscanf(fp, "%" SCNu16 "%" SCNu16 "%" SCNu16 "\n", &src_id, &dst_id, &weight) != EOF)
	{		
		addEdge(&(g[src_id-1]), dst_id, weight);
		if(src_id != dst_id)
		addEdge(&(g[dst_id-1]), src_id, weight);
	}
	
	
	fclose(fp);  
	return g;
}

void addEdge(Graph *g,uint16_t dst, uint16_t wght)
{
	struct t_Edge* tmp;
	
	//printf("Adding %d %d\n",dst, wght);
	tmp = malloc(sizeof(struct t_Edge));
	tmp->dst_id=dst;
	tmp->weight=wght;
	tmp->next=NULL;
	
	if(g)
	{
		tmp->next =*g;
		*g = tmp;
	}
	else
	{
		*g = tmp;
	
	}

}

void showGraph(Graph* g, uint16_t size)
{
	uint16_t i;
	struct t_Edge* tmp;
	for(i=0;i<size;i++)
	{
		
		tmp = g[i];
		printf("Node %d:",i+1);
		while(tmp != NULL)		{
		
			printf(" (%d %d)-%d",i+1,tmp->dst_id, tmp->weight);
			tmp=tmp->next;
			if(tmp) printf(",");
		}
		printf("\n");		
	}
}






