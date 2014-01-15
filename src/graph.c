#include "graph.h"
#include "debug.h"
#include <stdlib.h>


#define MAX_CHARS 64



/*Zwroc liczbe wiercholkow*/
int getVerticesCount(char *filename){
	FILE *fp;
	int src_id = 0, dst_id = 0, weight;
	int v_count = 0;
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%d %d %d\n", &src_id, &dst_id, &weight) != EOF)
	{
		if(src_id > v_count) v_count = src_id;
		if(dst_id > v_count) v_count = dst_id;		
	}
	fclose(fp);
#ifdef DEBUG
	printf("Graph contains %d vertices\n", v_count+1);
#endif
	
	
	return v_count+1;
	
}
/*Tworzenie grafu*/
Graph* createGraph(int size){
	Graph  *g;	
	int src_id, dst_id, weight,i;
	
	
	g  = malloc( size * sizeof( struct t_Vertice *));
	
	

	for(i=0;i<size;i++)
	{
		g[i] = NULL ;
	}
	
	return g;
}
/*Wczytywanie grafu z pliku*/
Graph* fillGraph(Graph* g, int size, char *filename){

	FILE *fp;
	int src_id, dst_id, weight;
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%d %d %d\n", &src_id, &dst_id, &weight) != EOF)
	{		
		addVertice(&(g[src_id]), dst_id, weight);
		if(src_id != dst_id)
		addVertice(&(g[dst_id]), src_id, weight);
	}
	
	
	fclose(fp);  
	return g;
}

/*Dodawanie wierzcholka*/
void addVertice(Graph *g,int dst, int wght){
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

void showGraph(Graph* g, int size){
	int i;
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


/*Zwroc ilosc krawedzi*/
int getEdgeCount(char *filename){

	FILE *fp;
	int src_id = 0, dst_id = 0, weight;
	long int e_count = 0;
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%d %d %d\n", &src_id, &dst_id, &weight) != EOF)
	{
		e_count++;		
	}
	fclose(fp);
#ifdef DEBUG
	printf("Graph contains %ld edges\n", e_count);
#endif
	
	
	return e_count;

}



/*Tworzenie grafu- reprezentacja krawedziowa*/
EGraph* createEGraph(int v_size,long int e_size){

	EGraph* egraph;
	egraph = malloc(sizeof(EGraph));

	egraph->edges = malloc(e_size*sizeof(struct t_Edge));
	egraph->v_count = v_size;
	egraph->e_count = e_size;
	return egraph;	

}

/*Wczytywanie grafu z pliku- reprezentacja krawedziowa*/
EGraph* fillEGraph(EGraph* egraph, char *filename){

	FILE *fp;	
	int src_id, dst_id, weight; 
	long int i = 0;
	struct t_Edge *tmp; 
	
	
	fp = fopen(filename, "r");
	while ( fscanf(fp, "%d %d %d\n", &src_id, &dst_id, &weight) != EOF)
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

void showEGraph(EGraph* eg, long int size){
	int i;
	struct t_Edge* tmp;
	for(i=0;i<size;i++){
	
		
		tmp = &eg->edges[i];
		printf(" (%d %d)-%d",tmp->src_id,tmp->dst_id, tmp->weight);
			
		printf("\n");		
	}
}








