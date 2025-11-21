class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
        
    vector<int>parent;
    vector<int>rank;
    
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    
    void Union(int x, int y){
        int x_par=find(x);
        int y_par=find(y);
        
        if(x_par==y_par)return ;
        
        if(rank[x_par]>rank[y_par]){
            parent[y_par]=x_par;
        }else if(rank[x_par]<rank[y_par]){
            parent[x_par]=y_par;
        }else{
            parent[x_par]=y_par;
            rank[y_par]++;
        }
    }
    
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        parent.resize(V);
        rank.resize(V);
        for(int i=0; i<V; i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        
        for(int u=0; u<V; u++){
            for(int &v:adj[u]){
                if(u<v){
                    int par_u=find(u);
                    int par_v=find(v);
                    
                    if(par_u==par_v)return 1;//parent same->cycle detected
                    Union(u,v);
                }
            }
        }
        return 0;
    }
};
