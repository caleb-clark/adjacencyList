#include "vertex.h"

vertex::vertex(int label)
{
	label_ = label;
}

void vertex::add_edge(int end, int weight)
{
	edge new_edge(label_, end, weight);
	edge_list_.push_back(new_edge);
}