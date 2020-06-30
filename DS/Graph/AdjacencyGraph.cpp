#include<iostream>
#include<vector>
#include "Graph.cpp"
using namespace std;

class AdjacencyGraph : public Graph {

	int V;
	vector<vector<int> > adj;

public:
	AdjacencyGraph(int v) {
		this->V = v;
		for (int i = 0; i < V; i++) {
			vector<int> vrow;
			adj.push_back(vrow);
		}
	}

	void add_directed_edge(int a, int b, int w = 1) {
		adj[a].push_back(b);
	}

	void print() {
		for (int i = 0; i < this->V; i++) {
			cout << i;

			for (int j = 0; j < adj[i].size(); j++) {
				cout << "-->" << adj[i][j];
			}

			cout <<endl;
		}
	}

	vector<vector<int> > get_graph() {
		return adj;
	}

	int get_vertices_count() {
		return V;
	}
};

AdjacencyGraph get_default_input() {
	AdjacencyGraph graph(5);
	graph.add_directed_edge(0,1);
	graph.add_edge(0,3);
	graph.add_directed_edge(1,2);
	graph.add_directed_edge(2,3);	
	return graph;
}
// int main() {
// 	AdjacencyGraph graph(5);
// 	graph.add_directed_edge(0,1);
// 	graph.add_edge(0,3);
// 	graph.add_directed_edge(1,2);
// 	graph.add_directed_edge(1,4);
// 	graph.add_directed_edge(2,3);
// 	graph.print();
// }