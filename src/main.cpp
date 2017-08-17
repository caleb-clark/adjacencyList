#include <iostream>
#include <string>

#include "graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string filename="";
    if(argv[1] == NULL){throw "no file given";}
    else filename = argv[1];
    cout << filename << endl;
    cout << endl;
	graph* g = new graph(filename);
	g->build_graph();
	g->display_graph();
	cout << endl;
	int q = 0;
	g->DFS(*(g->adj_list.at(0)),q);
	g->display_graph();
	//g->printTopological();

	//g->partition();
	//g->shortestPath(0,6);

}
