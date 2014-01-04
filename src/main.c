
#include "graph.h"
#include "set.h"


int main(int argc, char *argv[])
{
	Graph* main_graph;
	struct t_Set *tmp;
    uint16_t size;
	
	
	
	if(argc < 2)
	{
		return 0;
	}
	
	
	size = getVerticesCount(argv[1]);
	main_graph = createGraph(size);
	main_graph = fillGraph(main_graph, size, argv[1]);
	showGraph(main_graph, size);
	
	/*tmp = createSet(10);
	addElement(tmp,1);
	addElement(tmp,2);
	printf("%d %d %d\n", tmp->set[0], tmp->set[1], tmp->size);
	prim(main_graph,size);*/
	
	
	return 0;
}