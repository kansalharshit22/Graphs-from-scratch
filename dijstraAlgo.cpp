class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // adjacency list: node -> list of (neighbor, weight)
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});   // if graph is undirected
        }

        // min-heap: (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // relax all edges
            for (auto &edge : adj[node]) {
                int adjNode = edge.first;
                int wt = edge.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
//-----------------------------------------------//
// using set->erase old val in set avoid unnecessary processing
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        vector<int>res(V,INT_MAX);
        set<pair<int,int>>st;
        res[src]=0;
        st.insert({0,src});//distance,node
        
        while(!st.empty()){
            auto &it=*st.begin();
            int node=it.second;
            int d=it.first;
            st.erase(it);
            
            for(auto &vec:adj[node]){
                
                if(d+vec.second<res[vec.first]){
                    if(res[vec.first]!=INT_MAX)st.erase({res[vec.first],vec.first});
                
                    res[vec.first]=d+vec.second;
                    st.insert({d+vec.second,vec.first});
                }
            }
        }
        return res;
    }
};
