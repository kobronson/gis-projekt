
#include "debug.h"
#include "set.h"
#include "prim.h"


int main(int argc, char *argv[])
{
	Graph* main_graph, *result_graph;
	struct t_VSet *tmp;
	struct t_ESet *tmp2;
	struct t_Edge edg;
    uint16_t size;
	
	
	
	if(argc < 2)
	{
		return 0;
	}
	
	
	size = getVerticesCount(argv[1]);
	/* main_graph = createGraph(size);
	main_graph = fillGraph(main_graph, size, argv[1]);
	showGraph(main_graph, size);
	
	result_graph = prim(main_graph, size);
	printf("\n========================================\n");
	showGraph(result_graph, size); */
	
	
	tmp2 = createESet(size);
	edg.src_id = 1;
	edg.dst_id = 2;
	addESet(tmp2,&edg );
	edg.src_id = 3;
	edg.dst_id = 4;
	addESet(tmp2,&edg );
	
	
	printf("%d %d %d\n", tmp2->eset[0].src_id, tmp2->eset[1].src_id, tmp2->size);
	
	/*tmp = createSet(10);
	addElement(tmp,1);
	addElement(tmp,2);
	printf("%d %d %d\n", tmp->set[0], tmp->set[1], tmp->size);
	prim(main_graph,size);*/
	
	
	return 0;
}