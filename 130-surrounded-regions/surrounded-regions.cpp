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
    void dfs(vector<vector<char>> &mat,queue<pair<int,int>> &q1,vector<vector<int>> &visited){

        int n=mat.size();
        int m=mat[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q1.empty()){
            auto ele=q1.front();
            q1.pop();
            int row=ele.first;
            int col=ele.second;

         

            for(int i=0;i<4;i++){
                int newrow = row+drow[i];
                int newcol = col+dcol[i];

                if(isvaild(newrow,newcol,n,m) && mat[newrow][newcol]=='O' && visited[newrow][newcol]==0){
                    q1.push({newrow,newcol});
                    visited[newrow][newcol]=1;
                }
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
       
        int n=board.size();
        int m=board[0].size();

       vector<vector<char>> ans(n,vector<char>(m,'X'));
       vector<vector<int>> visited(n,vector<int>(m,0));
       queue<pair<int,int>> q1;
       
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q1.push({i,j});
                    visited[i][j]=1;
                    
                  
                }
            }
        }
        dfs(board,q1,visited);

     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
       
    }
};