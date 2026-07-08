//https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        int sum=0;
        vector<bool>visited(V,false);
        
        typedef pair<int,int> P;
        priority_queue<P,vector<P>,greater<P>>pq;
        
        //let start node 0
        pq.push({0,0});//{weight,node} 
        //no need to track parent
        
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            
            if(visited[t.second])continue;//if already vivisted avooid exploring ie its already part of mst
            
            visited[t.second]=true;//it has min edge weight marks as vivisted when popping
            sum+=t.first;
            for(auto &v:adj[t.second]){
                
                if(!visited[v.first])pq.push({v.second,v.first});
                
            }
        }
        return sum;
    }
};
