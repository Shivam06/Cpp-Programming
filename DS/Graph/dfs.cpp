#include "AdjacencyGraph.cpp"

void dfs_util(vector<vector<int> > adj, int s, vector<bool>& visited) {
	/*
		Complete the code below.
	*/

	cout << s << " ";
	visited[s] = true;

	for (auto itr = adj[s].begin(); itr != adj[s].end(); itr++) {
		if (visited[*itr])
			continue;

		visited[*itr] = true;
		dfs_util(adj, *itr, visited);
	}
}

void dfs(AdjacencyGraph graph) {

	vector<bool> visited(graph.get_vertices_count(), false);
	for (int i = 0;i < graph.get_vertices_count(); i++) {
		if (visited[i]) {
			continue;
		}
		dfs_util(graph.get_graph(), i, visited);
	}
}

int main() {
	AdjacencyGraph graph = get_default_input();
	graph.add_directed_edge(4,2);
	graph.print();
	dfs(graph);
}