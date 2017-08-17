#include <list>
#include "edge.h"
#ifndef VERTEX_H
#define VERTEX_H

class vertex 
{
public:
	int label_;
	bool visited_;
	int timestamp_ [2] = {-1,-1};

	std::list<edge> edge_list_;

	vertex(int label);

	void add_edge(int end, int weight = 0);
};


#endif