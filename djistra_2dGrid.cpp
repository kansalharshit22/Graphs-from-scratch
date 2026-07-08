//djitra simlar to bfs in 2d matrix
//1091
class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)return -1;//invalid start
        typedef pair<int,pair<int,int>>P;
        vector<vector<int>>res(n,vector<int>(n,INT_MAX-1));

        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        res[0][0]=0;
        grid[0][0]=1;//marks as visited

        while(!pq.empty()){
            P t=pq.top();
            int d=t.first;
            int x=t.second.first, y=t.second.second;
            pq.pop();
            
            for(auto &dir:directions){
                int i=x+dir[0];
                int j=y+dir[1];
                int dist=d+1;

                if(i>=0&&i<n&&j>=0&&j<n&&grid[i][j]==0){
                    if(dist<res[i][j]){
                        res[i][j]=dist;
                        pq.push({dist,{i,j}});
                    }
                    grid[i][j]=1;
                }
            }
        }
        int ans=res[n-1][n-1]+1;
        return ans==INT_MAX?-1:ans;
    }
};
//follow up as unoform weights can be done using standarad queue
