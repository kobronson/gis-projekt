
#include "graph.h"



int main(int argc, char *argv[])
{
	Graph* main_graph;
    
	
	if(argc < 2)
	{
		return 0;
	}
	
	main_graph = createGraph(argv[1]);
	
	
	return 0;
}