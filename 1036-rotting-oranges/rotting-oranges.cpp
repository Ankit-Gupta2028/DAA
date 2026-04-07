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
    void dfs(vector<vector<int>> &grid,int &min,vector<vector<int>> &visited,queue<pair<int,int>> &q1){
        int n=grid.size();
        int m=grid[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        
        

        while(!q1.empty()){
            int size=q1.size();
            min+=1;

            for(int i=0;i<size;i++){
                auto ele=q1.front();
                q1.pop();

                int row = ele.first;
                int col = ele.second;

                for(int i=0;i<4;i++){

                    int newrow=row+drow[i];
                    int newcol=col+dcol[i];
              

                    if(isvaild(newrow,newcol,n,m)){
                        if(grid[newrow][newcol]==1 && visited[newrow][newcol]==0){
                            visited[newrow][newcol]=1;
                            q1.push({newrow,newcol});
                        }
                    }

                }
                
            }
        }


    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
       int m=grid[0].size();
        queue<pair<int,int>> q1;

       int min=-1;
       vector<vector<int>> visited(n,vector<int>(m,0) );

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q1.push({i,j});
            }
        }
       }
       dfs(grid,min,visited,q1);

        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j]==0){
                return -1;
            }
        }
       }
       if(min==-1){
        return 0;
       }
       return min;

    }
};