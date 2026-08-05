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

//3341 min time to reach last room
class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>>time(n,vector<int>(m,INT_MAX));//result vector
        time[0][0]=0;

        typedef pair<int,pair<int,int>> p;
        priority_queue< p, vector<p>, greater<p>>pq;//min heap
        
        pq.push({0,{0,0}});//start node

        while(!pq.empty()){
            int curr=pq.top().first;
            auto [i,j]=pq.top().second;
            pq.pop();

            if(i==n-1&& j==m-1)return curr;//we reach destination
            
            //finding time to mve to adacent cell
            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];

                if(i_<0||i_>=n||j_<0||j_>=m)continue;
                
                int newtime=(moveTime[i_][j_]>curr)?moveTime[i_][j_]+1:curr+1;
                
                if(newtime>=time[i_][j_])continue;//do not upadte

                time[i_][j_]=newtime;
                pq.push({newtime,{i_,j_}});
            }

        }

        return -1;
    }
};
