// Detect cycle in a Directed Graph using DFS + Recursion Stack
class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inStack) {

        visited[u] = true;
        inStack[u] = true;

        for (int v : adj[u]) {

            // If not visited, DFS further
            if (!visited[v] && dfs(v, adj, visited, inStack))
                return true;

            // If already in recursion stack → back edge → cycle
            else if (inStack[v])
                return true;
        }

        inStack[u] = false;
        return false;
    }


    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Build directed graph
        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        vector<bool> visited(V, false);
        vector<bool> inStack(V, false);

        // Check all nodes (graph may be disconnected)
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfs(i, adj, visited, inStack))
                return true;
        }

        return false;
    }
};
