class Solution {
int min_path(vector<vector<int>>& matrix,int row,int col,int curr_row,int curr_col,vector<vector<int>> &dp){
    if(curr_row == 0 ){
        return matrix[curr_row][curr_col];
    }

    if(dp[curr_row][curr_col] != INT_MAX){
        return dp[curr_row][curr_col];
    }


    int up = INT_MAX;
    int up_left = INT_MAX;
    int up_right = INT_MAX;
    
    if(curr_row-1 >=0 ){
        up = matrix[curr_row][curr_col]+min_path(matrix,row,col,curr_row-1,curr_col,dp);
    }
     if(curr_row-1 >= 0 && curr_col-1 >= 0){
        up_left = matrix[curr_row][curr_col]+min_path(matrix,row,col,curr_row-1,curr_col-1,dp);
    }

     if(curr_row-1 >=0  && curr_col+1 <= col){
        up_right = matrix[curr_row][curr_col]+min_path(matrix,row,col,curr_row-1,curr_col+1,dp);
    }

    return dp[curr_row][curr_col]=min(up,min(up_left,up_right));

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));

        int ans = INT_MAX;

        for(int i=1;i<=m;i++){
            ans = min(ans,min_path(matrix,n-1,m-1,n-1,m-i,dp));
        }

        return ans;
    }
};