#include<iostream>
#include<vector>
#include "Graph.cpp"
using namespace std;

class MatrixGraph : public Graph {

	int V;
	vector<vector<int> > mat;

public:
	MatrixGraph(int v) {
		this->V = v;
		vector<vector<int> > M(v, vector<int>(v));
		mat= M;
	}

	void add_directed_edge(int a, int b, int w = 1) {
		this->mat[a][b] = w;
	}

	void print() {
		for (int i = 0; i < this->V; i++) {
			for (int j = 0; j < this->V; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	MatrixGraph graph(5);
	graph.add_edge(0,1);
	graph.add_directed_edge(2,3);
	graph.print();
}

