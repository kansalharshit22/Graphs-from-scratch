// Topological Sort (DFS + Stack)
// Author: Harshit
// Description: Returns topological order of a directed graph.

class Solution {
public:

    stack<int> st;

    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v])
                dfs(adj, v, visited);
        }

        st.push(u); // post-order push
    }


    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> visited(V, false);

        // Run DFS from all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfs(adj, i, visited);
        }

        // Extract topological order
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};
