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




uint16_t getVerticesCount(char *filename){
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
	printf("Graph contains %d vertices\n", v_count+1);
	
	
	return v_count+1;
	
}

Graph* createGraph(uint16_t size){
	Graph  *g;	
	uint16_t src_id, dst_id, weight,i;
	
	
	g  = malloc( size * sizeof( struct t_Vertice *));
	
	

	for(i=0;i<size;i++)
	{
		g[i] = NULL ;
	}
	
	return g;
}

Graph* fillGraph(Graph* g, uint16_t size, char *filename){

	FILE *fp;
	uint16_t src_id, dst_id, weight;
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%" SCNu16 "%" SCNu16 "%" SCNu16 "\n", &src_id, &dst_id, &weight) != EOF)
	{		
		addVertice(&(g[src_id]), dst_id, weight);
		if(src_id != dst_id)
		addVertice(&(g[dst_id]), src_id, weight);
	}
	
	
	fclose(fp);  
	return g;
}

void addVertice(Graph *g,uint16_t dst, uint16_t wght){
	struct t_Vertice* tmp;
	
	tmp = malloc(sizeof(struct t_Vertice));
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

void showGraph(Graph* g, uint16_t size){
	uint16_t i;
	struct t_Vertice* tmp;
	for(i=0;i<size;i++)
	{
		
		tmp = g[i];
		printf("Node %d:",i);
		while(tmp != NULL)		{
		
			printf(" (%d %d)-%d",i,tmp->dst_id, tmp->weight);
			tmp=tmp->next;
			if(tmp) printf(",");
		}
		printf("\n");		
	}
}


uint16_t getEdgeCount(char *filename){

	FILE *fp;
	uint16_t src_id = 0, dst_id = 0, weight;
	uint16_t e_count = 0;
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%" SCNu16 "%" SCNu16 "%" SCNu16 "\n", &src_id, &dst_id, &weight) != EOF)
	{
		e_count++;		
	}
	fclose(fp);
	printf("Graph contains %d edges\n", e_count);
	
	
	return e_count;

}




EGraph* createEGraph(uint16_t v_size,uint16_t e_size){

	EGraph* egraph;
	egraph = malloc(sizeof(EGraph));

	egraph->edges = malloc(e_size*sizeof(struct t_Edge));
	egraph->v_count = v_size;
	egraph->e_count = e_size;
	return egraph;	

}
EGraph* fillEGraph(EGraph* egraph, char *filename){

	FILE *fp;	
	uint16_t src_id, dst_id, weight, i = 0 ;
	struct t_Edge *tmp; 
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%" SCNu16 "%" SCNu16 "%" SCNu16 "\n", &src_id, &dst_id, &weight) != EOF)
	{		
		tmp = &egraph->edges[i];
		tmp->src_id = src_id;
		tmp->dst_id = dst_id;
		tmp->weight = weight;
		
		i++;
	}
	
	
	fclose(fp);  
	return egraph;
	

	
}

void showEGraph(EGraph* eg, uint16_t size){
	uint16_t i;
	struct t_Edge* tmp;
	for(i=0;i<size;i++){
	
		
		tmp = &eg->edges[i];
		printf(" (%d %d)-%d",tmp->src_id,tmp->dst_id, tmp->weight);
			
		printf("\n");		
	}
}








