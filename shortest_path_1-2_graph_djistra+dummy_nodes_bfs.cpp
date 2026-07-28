//Shortest Path in 1-2 Graph

// using djistra till we reach dest node
class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        typedef pair<int,int>p;
        vector<vector<p>>adj(V);
        
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        vector<int>dist(V,INT_MAX);
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            p u=pq.top();
            pq.pop();
            
            if(dist[u.second]<=u.first)continue;
            
            dist[u.second]=u.first;
            if(u.second==dest)return dist[u.second];//shortest jaldi mil jayega
            
            for(auto &v:adj[u.second]){
                int cost= u.first+v.second;
                pq.push({cost,v.first});
            }
        }
        
        return -1;
    }
};

//----------------------------------------------------------------------------------------------------------//
//using bfs ->dummy nodes slipt edge weight 2 into dummy nodes
//a-----2------>b
//a--1---dummy----1--->b

class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V + edges.size());
        int nodes = V;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(w == 1){

                adj[u].push_back(v);
                adj[v].push_back(u);

            }else{
                //incase of weight as 2, add a dummy node 1-->dummy-->2
                int dummy = nodes++;

                adj[u].push_back(dummy);
                adj[dummy].push_back(u);

                adj[dummy].push_back(v);
                adj[v].push_back(dummy);
            }
        }

        vector<int> dist(nodes, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while(!q.empty()){

            int u = q.front();
            q.pop();

            for(int v : adj[u]){

                if(dist[v] != -1) continue;

                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        return dist[dest];
    }
};


//follow up in case of 0-1 graph->use a deque
// push front if weight as 0
