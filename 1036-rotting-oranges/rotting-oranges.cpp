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
    void bfs(vector<vector<int>> &grid,queue<pair<int,int>> &q1,int &min,int &cnt){

       int n=grid.size();
       int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

       while(!q1.empty()){
            int qsize=q1.size();
          
             cnt+=qsize;
            for(int i=0;i<qsize;i++){

                auto ele=q1.front();
                int Row=ele.first;
                int Col=ele.second;
                q1.pop();

                for(int i=0;i<4;i++){
                    int newrow=Row+drow[i];
                    int newcol=Col+dcol[i];
                    if(isvaild(newrow,newcol,n,m)){
                        if(grid[newrow][newcol]==1){

                            q1.push({newrow,newcol});
                            grid[newrow][newcol]=2;
                        }
                    }
                }
                
            }
            if(!q1.empty()){
                min+=1;
            }
           
       }

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
          
       queue<pair<int,int>> q1;
       int n=grid.size();
       int m=grid[0].size();

        int total=0;

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                total+=1;
            }
            if(grid[i][j]==2){
                q1.push({i,j});
    
            }
        }
       }
       int min=0;
       int cnt=0;
       bfs(grid,q1,min,cnt);

        if(total==cnt){
            return min;
        }
       return -1;
    }
};