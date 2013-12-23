#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdint.h>

struct t_Edge
{

	uint16_t nodeId; //vertice on the other side of the edge
    uint8_t  weight; //weight of the edge	

} Edge;

Edge  graph[ UINT16_MAX ];
 




#endif /* GRAPH_H_ */

