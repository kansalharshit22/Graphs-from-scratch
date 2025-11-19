class Solution {
public:

    // DFS helper function to color the graph
    // curr        -> current node
    // currColor   -> color to assign (0 or 1)
    // color[]     -> stores assigned colors
    // adj         -> adjacency list
    bool check(unordered_map<int, vector<int>>& adj,
               int curr,
               vector<int>& color,
               int currColor)
    {
        // Assign color to the current node
        color[curr] = currColor;

        // Explore all neighbors
        for (int &v : adj[curr]) {

            // If neighbor has the same color → not bipartite
            if (color[v] == currColor)
                return false;

            // If neighbor is uncolored, recursively color it
            if (color[v] == -1) {
                if (!check(adj, v, color, 1 - currColor))
                    return false;
            }
        }

        // No conflicts found
        return true;
    }


    // Function to check whether the graph is bipartite
    bool isBipartite(int V, vector<vector<int>>& edges) {

        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);  // Graph is undirected
        }

        // -1 means uncolored, 0/1 are two different colors
        vector<int> color(V, -1);

        // Handle disconnected graphs by checking all components
        for (int i = 0; i < V; i++) {

            // If not colored yet, start DFS coloring
            if (color[i] == -1) {
                if (!check(adj, i, color, 1))
                    return false;
            }
        }

        return true;   // Successfully colored → graph is bipartite
    }
};
