#include "graph.h"
#include <iostream>
#include <stack>
// build a graph according to the input file
void graph::build_graph()
{
 
	int a=0;
	bool checker = true;
	
    int counter = 0;
	while(input_file >> a)
	{	
		if (checker) {
			vertex * v = new vertex(counter++);
			adj_list.push_back(v);
			checker = false;
		}

		if (a != -1) {
			adj_list.back()->add_edge(a);
		} else {
			checker = true;
		}
	}
};

void graph::display_graph() {
	for(int i = 0; i < adj_list.size(); i++)
	{
		std::cout << adj_list.at(i)->label_ << "(" << adj_list.at(i)->timestamp_[0] << "," << adj_list.at(i)->timestamp_[1] << "): ";
		for(auto it = adj_list.at(i)->edge_list_.begin(); it != adj_list.at(i)->edge_list_.end(); it++){
			std::cout << "->" << it->end_;
		}
		std::cout << std::endl;
	}
};

void graph::DFS(vertex& v, int& order)
{
	std::cout << "order: " << order << std::endl;
	std::cout << "label: " << v.label_ << std::endl;
	if (v.timestamp_[0] != -1) {
		return;
	}
	v.timestamp_[0] = order++;
	std::cout << v.label_ << std::endl;
	for (auto it = v.edge_list_.begin();
		it != v.edge_list_.end(); it++) {
		std::cout << "it->start_: " << it->end_ << std::endl;
		std::cout << adj_list.at(it->end_)->label_ << std::endl;
		DFS(*adj_list.at(it->end_), order);
	}
	v.timestamp_[1] = order++;
}
void graph::DFS_iterative(vertex& v)
{
	int counter = 0;
	std::stack<vertex*> s;
	
	s.push(&v);
	
	while (!s.empty()) {
		v = *(s.top());
		s.pop();
		v.timestamp_[0] = counter;
		counter++;
		for (auto it = v.edge_list_.begin();
		it != v.edge_list_.end(); it++) {
			s.push(adj_list.at(it->end_));
		}
	}

}


