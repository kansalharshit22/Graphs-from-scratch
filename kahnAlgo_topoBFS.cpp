vector<int> topoSort(int V, vector<vector<int>>& edges) {

    // Build adjacency list
    unordered_map<int, vector<int>> adj;
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
    }

    // Compute indegree of each node
    vector<int> indeg(V, 0);
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            indeg[v]++;
        }
    }

    // Push all nodes with 0 indegree
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    // BFS / Kahn's Algorithm
    vector<int> res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    return res; // if graph has cycle -> res.size() < V
}
