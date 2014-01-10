
#include "debug.h"
#include "graph.h"
#include "set.h"
#include "prim.h"
#include "kruskal.h"


int main(int argc, char *argv[])
{
	Graph* main_graph, *result_graph;
	struct t_Set *tmp;
    uint16_t size,e_size;
	EGraph* e_graph;
	
	
	if(argc < 2)
	{
		return 0;
	}
	
	
	size = getVerticesCount(argv[1]);
	e_size = getEdgeCount(argv[1]);
	e_graph = createEGraph(size,e_size);
	e_graph = fillEGraph(e_graph,argv[1]);
	//showEGraph(e_graph, e_size);
	e_graph = kruskal(e_graph);
	showEGraph(e_graph, e_size);
	
	
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