class Solution {
int max_cherry(int row,int col,int r1, int c1,int c2,vector<vector<int>>& matrix,vector<vector<vector<int>>> &dp){

    if( c1 < 0 || c1 > col -1 || c2 < 0 || c2 > col -1 ){
        return -1e9;
    }
    if( r1==row-1  ){
        if( c1 == c2){
            return matrix[r1][c1];
        }else{
             return matrix[r1][c1]+matrix[r1][c2];
        }
    }

    if(dp[r1][c1][c2] != -1){
        return dp[r1][c1][c2];
    }
    int ans = INT_MIN;
    for(int i = -1;i<=1;i++){
        for(int j = -1;j<=1;j++){
            int maxi =0;
            if( c1 == c2){
                 maxi = matrix[r1][c1]+max_cherry(row,col,r1+1,c1+i,c2+j,matrix,dp);
            }else{
                 maxi = matrix[r1][c1]+matrix[r1][c2]+max_cherry(row,col,r1+1,c1+i,c2+j,matrix,dp);
            }
            ans = max(ans,maxi);
        }
    }
    return dp[r1][c1][c2] = ans;
}
public:
    int cherryPickup(vector<vector<int>>& grid) {
          int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

        return max_cherry(n,m,0,0,m-1,grid,dp);

    }
};