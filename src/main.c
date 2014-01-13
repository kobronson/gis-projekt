
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
	struct timespec start, end;
	uint64_t timeElapsed;
	
	
	if(argc < 2)
	{
		return 0;
	}
	
	

	
	
	
	size = getVerticesCount(argv[1]);
	e_size = getEdgeCount(argv[1]);
	
	printf("=====================Prim \n");
	main_graph = createGraph(size);
	main_graph = fillGraph(main_graph, size, argv[1]);
	clock_gettime(CLOCK_MONOTONIC, &start);
	result_graph = prim(main_graph,size);
	clock_gettime(CLOCK_MONOTONIC, &end);
	//showGraph(result_graph, size);
	timeElapsed = timespecDiff(&end, &start);
	printf ("Prim time = %" PRIu64 "\n",timeElapsed);
	
	
	e_graph = createEGraph(size,e_size);
	e_graph = fillEGraph(e_graph,argv[1]);
	//showEGraph(e_graph, e_size);
	printf ("==================Kruskal\n");
	clock_gettime(CLOCK_MONOTONIC, &start);
	e_graph = kruskal(e_graph);
	clock_gettime(CLOCK_MONOTONIC, &end);
	timeElapsed = timespecDiff(&end, &start);
	showEGraph(e_graph, e_graph->v_count-1);
	printf ("Kruskal time = %" PRIu64 "\n",timeElapsed);
	
	/*main_graph = createGraph(size);
	main_graph = fillGraph(main_graph, size, argv[1]);
	showGraph(main_graph, size);
	
	result_graph = prim(main_graph, size);
	printf("\n========================================\n");
	showGraph(result_graph, size);
	
	printf("Contains eges %d",getEdgeCount(argv[1]));*/
	
	
	/*tmp = createSet(10);
	addElement(tmp,1);
	addElement(tmp,2);
	printf("%d %d %d\n", tmp->set[0], tmp->set[1], tmp->size);
	prim(main_graph,size);*/
	
	
	return 0;
}