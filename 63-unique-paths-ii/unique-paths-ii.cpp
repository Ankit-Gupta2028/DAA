class Solution {
int uniquePaths(vector<vector<int>>& matrix,int row , int col,vector<vector<int>> &dp ){
    if(row ==0 && col ==0 ){
        return 1;
    }
    if(matrix[row][col]==1){
        return 0;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }

    int up = 0;
    int left = 0;
    if(row > 0){
        up = uniquePaths(matrix,row-1,col,dp);
    }
    if(col > 0){
        left = uniquePaths(matrix,row,col - 1,dp);
    }
    dp[row][col]=left+up;
    return up+left;
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row  = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        if( obstacleGrid[0][0]== 1){
            return 0;
        }

        vector<vector<int>> dp(row,vector<int>(col,-1));

        return uniquePaths(obstacleGrid,row-1,col-1,dp);
    }
};