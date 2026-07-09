class Solution {
  public://DSU+Kruskal
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
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        sort(edges.begin(),edges.end(),[](vector<int>&vec1, vector<int>&vec2){
            return vec1[2]<vec2[2];
        });
        
        parent.resize(V);
        rank.resize(V);
        for(int i=0; i<V; i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        
        int sum=0;
        for(auto &vec:edges){
            
            if(find(vec[0])!=find(vec[1])){
                // they are not connected
                Union(vec[0],vec[1]);
                sum+=vec[2];//add edge weight
            }
            
            //if connected ->have same parent->ignore edge weight
        }
        
        return sum;
        
    }
};
