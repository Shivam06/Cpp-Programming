#include "AdjacencyGraph.cpp"
#include<queue>


void bfs(AdjacencyGraph graph, int s, vector<bool>& visited) {

	vector<vector<int> > adj = graph.get_graph();
	
	
	queue<int> q;
	if (visited[s])
		return;
	q.push(s);

	visited[s] = true;
	while(!q.empty()) {
		int v = q.front();
		cout << v << " ";
		q.pop();

		for (auto itr = adj[v].begin(); itr!=adj[v].end(); itr++) {
			if (!visited[*itr]) {
				q.push(*itr);
			}
			visited[*itr] = true;
		}		
	}
}

void bfs(AdjacencyGraph graph) {

	vector<bool> visited(graph.get_vertices_count(), false);
	for (int i = 0; i < graph.get_vertices_count(); i++) {
		bfs(graph, i, visited);
	}	
}

int main() {
	AdjacencyGraph graph = get_default_input();
	graph.print();
	bfs(graph);
}