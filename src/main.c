
#include "graph.h"



int main(int argc, char *argv[])
{
	Graph* main_graph;
    uint16_t size;
	
	
	
	if(argc < 2)
	{
		return 0;
	}
	
	size = getVerticesCount(argv[1]);
	main_graph = createGraph(argv[1]);
	
	showGraph(main_graph, size);
	
	return 0;
}