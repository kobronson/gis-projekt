#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#include <stdint.h>
#include "graph.h"


int compareEdges(const void* edge_1, const void* edge_2);
EGraph* kruskal(EGraph *graph);


#endif /* KRUSKAL_H_ */