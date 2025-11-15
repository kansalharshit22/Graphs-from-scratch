// traversal.cpp
// Basic DFS and BFS for an undirected graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // DFS helper
    void dodfs(vector<bool>& visited, vector<int> adj[], int u, vector<int>& res) {
        visited[u] = true;
        res.push_back(u);

        for (int &v : adj[u]) {
            if (!visited[v]) {
                dodfs(visited, adj, v, res);
            }
        }
    }

    // DFS driver
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> visited(V, false);

        dodfs(visited, adj, 0, res);
        return res;
    }

    // BFS
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<bool> vted(V, false);

        queue<int> q;
        q.push(0);
        vted[0] = true;
        bfs.push_back(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &v : adj[node]) {
                if (!vted[v]) {
                    bfs.push_back(v);
                    q.push(v);
                    vted[v] = true;
                }
            }
        }
        return bfs;
    }
};

int main() {
    // You can add testing code here if you want
    return 0;
}
