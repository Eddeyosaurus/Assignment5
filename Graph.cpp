#include "Graph.h"

Graph::Graph()
{
	adjList = NULL;
}

Graph::~Graph()
{

}

Graph::Graph(const Graph& other)
{
	numNodes = other.numNodes;
	adjList = other.adjList;	
}

Graph& Graph::operator=(const Graph& other)
{
	numNodes = other.numNodes;
	adjList = other.adjList;
}

void Graph::SetNumNodes()
{
	int temp;

	cout << "How many nodes in the graph? ";
	cin >> temp;

	while(cin.fail()){
		cout << "\nInput failed. Please try again.\n";
		cout << "How many nodes in the graph? ";
		cin >> temp;
	}

	numNodes = temp;

	adjList = new List[temp];
}

void Graph::SetAdjList()
{
	for(int i = 0; i < numNodes; i++)
	{
		int input;
		
		cout << "Please enter connecting nodes for node " << i;
		cin >> input;
		
		while(!cin.fail())
		{
			while(input == i)
			{
				cout << "Node may not be adjacent with self.\n";
				cin >> input;
			}

			adjList[i].Insert(input);
			cin >> input;
		}

		adjList[i].Print();
	}
}