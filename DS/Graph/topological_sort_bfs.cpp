#include "AdjacencyGraph.cpp"

vector<int> topoSort(int V, vector<vector<int> > adj) {
    
    vector<int> output;
    queue<int> q;
    vector<int> visited(V, 0);
    vector<int> indegree(V,0);
    
    // TODO - Find indegree of all the vertices O(E)
    for (int i = 0; i < V; i++) {
        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++) {
            indegree[*itr]++;
        }
    }
    
    // TODO - Push vertices with 0 indegree in the queue.
    for (int i =0; i < indegree.size(); i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    
    // TODO - BFS for topoSort.
    while (!q.empty()) {
        
        int v = q.front();
        output.push_back(v);
        q.pop();
        
        for (auto itr = adj[v].begin(); itr != adj[v].end(); itr++) {
            indegree[*itr]--;
            if (indegree[*itr] == 0) {
                q.push(*itr);
            }
        }
    }
    
    return output;
}


int main() {
    AdjacencyGraph adg = get_dag_input();
    vector<int> output = topoSort(adg.get_vertices_count(), adg.get_graph());
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    return 0;
}