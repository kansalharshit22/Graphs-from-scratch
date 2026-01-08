class Solution {//lc:695
public://using bfs
    int m,n,res;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>&grid,int i,int j,int cnt){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            cnt++;
            for(auto &dir:directions){
                int i_=it.first+dir[0];
                int j_=it.second+dir[1];
                if(i_<0||i_>=m||j_<0||j_>=n||grid[i_][j_]==0)continue;
                q.push({i_,j_});
                grid[i_][j_]=0;
            }
        }
        res=max(res,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        res=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0)continue;
                bfs(grid,i,j,0);
            }
        }
        return res;
    }
};
