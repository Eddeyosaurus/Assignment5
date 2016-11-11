#ifndef GRAPH_
#define GRAPH_

#include <iostream>
#include "List.h"


using namespace std;


class Graph{
	public:
		Graph();
		~Graph();
		Graph(const Graph& other);
		Graph& operator=(const Graph& other);

		void SetNumNodes();
		//Sets the number of nodes in the graph;
		//Pre: 
		//Post: numNodes is set;
		
		void SetAdjList(); 
		//Sets each nodes adjcencies
		//Pre: SetNumNodes has been called
		//Post: All adjacencies set.

	private:

		int numNodes;

		List* adjList;

};
#endif