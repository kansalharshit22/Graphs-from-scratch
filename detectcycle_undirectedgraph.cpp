/*
    cycle_detection.cpp
    -------------------------------------
    Detects cycles in an undirected graph 
    using both DFS and BFS approaches.

    Author: Harshit
    Description:
        - Graph may be disconnected
        - Input: number of vertices & edge list
        - Output: true/false for cycle detection
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        DFS-based cycle detection
        -------------------------
        - parent parameter ensures we don't treat
          the edge back to parent as a cycle.
        - If we find a visited neighbor that is not
          the parent, a cycle exists.
    */
    bool dfs(unordered_map<int, vector<int>>& adj,
             int u,
             vector<bool>& visited,
             int parent) {

        visited[u] = true;

        for (int &v : adj[u]) {

            // Ignore the edge back to parent
            if (v == parent)
                continue;

            // If the neighbor is already visited -> cycle
            if (visited[v])
                return true;

            // DFS recursion
            if (dfs(adj, v, visited, u))
                return true;
        }

        return false;
    }


    /*
        BFS-based cycle detection
        -------------------------
        - Use queue storing (node, parent)
        - For each visited neighbor v:
            - if v is not the parent → cycle exists
    */
    bool bfs(unordered_map<int, vector<int>>& adj,
             int start,
             vector<bool>& visited) {

        queue<pair<int, int>> q;  // (node, parent)
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty()) {

            auto [node, parent] = q.front();
            q.pop();

            for (int &nbr : adj[node]) {

                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, node});

                } else if (nbr != parent) {
                    // Visited neighbor not equal to parent -> cycle
                    return true;
                }
            }
        }

        return false;
    }


    /*
        Main function: isCycle
        ----------------------
        - Builds adjacency list from edge list
        - Runs BFS or DFS on each component
        - Ensures disconnected graphs are handled
    */
    bool isCycle(int V, vector<vector<int>>& edges) {

        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        // Use BFS or DFS for each unvisited component
        for (int i = 0; i < V; i++) {

            if (!visited[i]) {
                // BFS version
                if (bfs(adj, i, visited))
                    return true;

                // Or DFS version:
                /*
                if (dfs(adj, i, visited, -1)) track parent initially -1
                    return true;
                */
            }
        }

        return false;
    }
};

