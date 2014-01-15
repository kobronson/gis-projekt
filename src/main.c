
#include "debug.h"
#include "graph.h"
#include "set.h"
#include "prim.h"
#include "kruskal.h"
#include "time.h"
#include <inttypes.h>
#include <stdint.h>
#include <time.h>

int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

int main(int argc, char *argv[])
{
	Graph* main_graph;
	struct t_Set *tmp;
    int size,e_size;
	EGraph* e_graph;
	struct timespec start, end;
	uint64_t timeElapsed;
	
	
	if(argc < 3)
	{
		return 0;
	}
	
	

	
	
	printf ("Processing graph %s\n",argv[1]);
	size = getVerticesCount(argv[1]);
	e_size = getEdgeCount(argv[1]);
	/*==========Prim==============*/
	if(*argv[2] == 'p'){
		main_graph = createGraph(size);
		main_graph = fillGraph(main_graph, size, argv[1]);
	
		clock_gettime(CLOCK_MONOTONIC, &start);
		prim(main_graph,size);
		clock_gettime(CLOCK_MONOTONIC, &end);
	
		timeElapsed = timespecDiff(&end, &start);
		printf ("MST Prim runtime = %" PRIu64 "ms\n",timeElapsed/1000000);
	}
	/*==========Kruskal==============*/
	if(*argv[2] == 'k'){
		e_graph = createEGraph(size,e_size);
		e_graph = fillEGraph(e_graph,argv[1]);
		
		clock_gettime(CLOCK_MONOTONIC, &start);
		e_graph = kruskal(e_graph);
		clock_gettime(CLOCK_MONOTONIC, &end);
	
		timeElapsed = timespecDiff(&end, &start);
#ifdef DEBUG
		showEGraph(e_graph, e_graph->v_count-1);
#endif
		printf ("MST Kruskal runtime = %" PRIu64 "ms\n",timeElapsed/1000000);
	}
	
	
	return 0;
}