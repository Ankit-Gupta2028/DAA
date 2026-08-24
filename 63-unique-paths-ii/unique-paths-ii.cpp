class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int row  = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row,vector<int>(col,0));

        for(int i=0 ;i<row;i++){
            for(int j=0;j<col;j++){

                if(obstacleGrid[i][j] == 1){
                    dp[i][j]=0;
                    continue;
                }


                int left = 0;
                int up = 0;

                if(i ==0 && j==0){
                    dp[i][j]=1;
                    
                }else{
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1];
                    }
                     dp[i][j]=left+up;
                }  
           
            }
        }

        return dp[row-1][col-1];
    
    }
};