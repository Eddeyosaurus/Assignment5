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
	string temp;
	stringstream s;

	cout << "How many nodes in the graph? ";
	getline(cin, temp);

	temp = ReadInput();

	cout << "\n\n";

	numNodes = temp;

	adjList = new List[temp];
}

void Graph::SetAdjList()
{
	int num;
	string input;
	stringstream sstream;

	for(int i = 0; i < numNodes; i++)
	{
		cout << "\nPlease enter connecting nodes for node " << i << ":\n";
		
		getline(cin, input);
		
		while(input != "")
		{
			num = CheckInput(input);

			while(num == i)
			{
				cout << "Node may not be adjacent with self.\n";
				getline(cin, input);
				num = CheckInput(input);
			}

			adjList[i].Insert(input);
			getline(cin,input);
		}

		adjList[i].Print();
	}
}

int List::CheckInput(string input)
{
	int num;
	stringstream sstream;
	sstream >> num;

	while(sstream.fail())
	{
		cout << "\nBad input, please try again: ";
		getline(cin, input);
		sstream(input);
		sstream >> num;
	}

	return num;
}