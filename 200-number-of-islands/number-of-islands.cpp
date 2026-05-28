class Solution {
bool isvaild(int row,int col,int n,int m){
    if(row <0 || row >= n || col== -1 || col>=m){
        return false;
    }
    return true;
}
void bfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int row,int col,int n,int m){

    queue<pair<int,int>> q1;
    q1.push({row,col});
    vis[row][col]=1;
    int Row[]={-1,0,0,1};
    int Col[]={0,-1,1,0};


    while(!q1.empty()){

        auto ele=q1.front();
        q1.pop();

        int row=ele.first;
        int col=ele.second;

      
        for(int i=0;i<4;i++){
           
                if(isvaild(row+Row[i],col+Col[i],n,m)){
                    if(grid[row+Row[i]][col+Col[i]]-'0'==1 && vis[row+Row[i]][col+Col[i]]==0){
                        vis[row+Row[i]][col+Col[i]]=1;
                        q1.push({row+Row[i],col+Col[i]});
                    }
                }
            
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(vis[i][j]==0 && grid[i][j]-'0' == 1 ){
                    island+=1;
                    bfs(grid,vis,i,j,n,m);
                }
            }
        }
        return island;
    }
};