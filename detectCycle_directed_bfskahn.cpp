class Solution {
  public:
    //using bfs-kan topoSort algo
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //step1 make adj
        unordered_map<int,vector<int>>adj;
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        // step2 make indegree vector
        vector<int>indeg(V);
        for(int i=0; i<V;i++){
            for(auto &v:adj[i]){
                indeg[v]++;
            }
        }
        
        // step3compute using using
        queue<int>q;
        for(int i=0; i<V;i++){
            if(indeg[i]==0)q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop(); cnt++;
            
            for(int &v:adj[u]){
                indeg[v]--;
                
                if(indeg[v]==0)q.push(v);
            }
        }
        return !(cnt==V);
        //agr count same matlab we hv visited every node and no cycle detected--->hence false
    }
};
