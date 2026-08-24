class Solution {

int unique_ways(int row,int col,int m,int n,vector<vector<int>> &dp){

    if(row == m-1 && col == n-1 ){
        return 1;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    int right = 0;
    int down = 0;
    if(col+1 <= n-1){
         right=unique_ways(row,col+1,m,n,dp);
    }
     if(row+1 <= m-1){
         down = unique_ways(row+1,col,m,n,dp);
    }
    return dp[row][col] = right+down;

}
public:
    int uniquePaths(int m, int n) {
        int row = 0;
        int col = 0;
  
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return unique_ways(row,col,m,n,dp);
    }
};