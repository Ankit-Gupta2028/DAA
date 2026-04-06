class Solution {
bool isvaild(int i,int j,int n,int m){
    if(i<0 || i>=n){
        return false;
    }
    if(j<0 || j>=m){
        return false;
    }
    return true;
}
void bfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q1;
        vis[i][j]=1;
        q1.push({i,j});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q1.empty()){
            auto ele=q1.front();
            q1.pop();
            int row=ele.first;
            int col=ele.second;

            for(int i=0;i<4;i++){
              int newrow=row+drow[i];
              int newcol=col+dcol[i];

                if(isvaild(newrow,newcol,n,m)){
                    if(grid[newrow][newcol]  == '1' && vis[newrow][newcol]==0){
                            vis[newrow][newcol]=1;
                            q1.push({newrow,newcol});
                    }
                }

                
            }
        }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] =='1' && vis[i][j]==0){
                    ans+=1;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};