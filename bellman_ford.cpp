//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>res(V,100000000);//INT_MAX
        res[src]=0;
        for(int cnt=0; cnt<V-1; cnt++){
            for(auto &e:edges){
                if(res[e[0]]!=100000000&&res[e[0]]+e[2]<res[e[1]]){
                    res[e[1]]=res[e[0]]+e[2];//relaxartion
                }
            }
        }
        
        //cycle detection
        bool iscycle=false;
        for(auto &e:edges){
                if(res[e[0]]!=100000000&&res[e[0]]+e[2]<res[e[1]]){
                    iscycle=true;
                }//some updation Vth time
        }
        
        if(iscycle)return {-1};
        return res;
    }
};
