class Solution {
private:
    bool isvaild(int i,int j,int n,int m){
    if(i<0 || i>=n){
        return false;
    }
    if(j<0 || j>=m){
        return false;
    }
    return true;
    
    }
    void bfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int row,int col){
        queue<pair<int,int>> q1;
        q1.push({row,col});
        visited[row][col]=1;

        int n=grid.size();
        int m = grid[0].size();



        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q1.empty()){

            auto ele = q1.front();
            int Row = ele.first;
            int Col = ele.second;
            q1.pop();

            for(int i=0;i<4;i++){
                int newrow=Row+drow[i];
                int newcol = Col+dcol[i];
                if(isvaild(newrow,newcol,n,m)){
                    if(grid[newrow][newcol]==1 && visited[newrow][newcol]==0){
                        q1.push({newrow,newcol});
                        visited[newrow][newcol]=1;
                    }
                }



            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1 && visited[i][j]==0){
                        bfs(grid,visited,i,j);
                    }
                }
            }
        }
        int enclaves=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    enclaves+=1;
                }
            }
        }
        return enclaves;
    }
};