#include <fstream>
#include <stack>
#include <vector>
#include "vertex.h"
#include "edge.h"

#ifndef GRAPH_H
#define GRAPH_H

class graph
{
public:
	std::vector <vertex*> adj_list;
	std::ifstream input_file;
	graph(std::string file_name) {
		input_file.open(file_name);
	};
	~graph() {
		for (auto it = adj_list.begin();
			it != adj_list.end(); it++) {
			delete (*it);
		}
	}
	// build a graph according to the input file
    void build_graph();
    // display the graph
    void display_graph();
    // depth first search
    void DFS(vertex& v, int& order);
    // depth first search non-recursive
    void  DFS_iterative(vertex& v);


};




#endif