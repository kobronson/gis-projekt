
#include "debug.h"
#include "graph.h"
#include "set.h"
#include "prim.h"
#include "kruskal.h"
#include "time.h"

#include <inttypes.h>


int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  return ((timeA_p->tv_sec ) - (timeB_p->tv_sec ));
}

int main(int argc, char *argv[])
{
	Graph* main_graph, *result_graph;
	struct t_Set *tmp;
    uint16_t size,e_size;
	EGraph* e_graph;
	clock_t start, end;
	double timeElapsed;
	
	
	if(argc < 2)
	{
		return 0;
	}
	
	

	
/******************Prim*************************/	
	/*if(*argv[2] == 'p'){
	size = getVerticesCount(argv[1]);
	e_size = getEdgeCount(argv[1]);
	
	printf("MST: Algorytm Prima dla grafu testowego %s\n",argv[1]);
	main_graph = createGraph(size);
	
	main_graph = fillGraph(main_graph, size, argv[1]);
		
	start = clock();
	
	result_graph = prim(main_graph,size);
	
	end = clock();
	timeElapsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf ("Prim czas = %lf \n",timeElapsed);
	}*/
#ifdef DEBUG
	showGraph(result_graph, size);
#endif	


/***************Kruskal************************/


	printf ("MST algorytm Kruskala dla grafu testowego %s\n",argv[1]);
	e_size = getEdgeCount(argv[1]);
	e_graph = createEGraph(size,e_size);
	e_graph = fillEGraph(e_graph,argv[1]);	
	start = clock();
	
	e_graph = kruskal(e_graph);
	
	end = clock();
	timeElapsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf ("Kruskal czas = %lf \n",timeElapsed);
#ifdef DEBUG
	showEGraph(e_graph, e_graph->v_count-1);
#endif
	
		
	
	
	
	return 0;
}