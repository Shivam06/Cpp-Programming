#include<iostream>
using namespace std;

class Graph {

	public: 
		virtual void add_edge(int a, int b, int w = 1) {
			this->add_directed_edge(a,b,w);
			this->add_directed_edge(b,a,w);
		}

		virtual void add_directed_edge(int a, int b, int w = 0) = 0;

		virtual void print() = 0;
};