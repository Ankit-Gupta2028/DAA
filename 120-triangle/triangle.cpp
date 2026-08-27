class Solution {
int min_path(vector<vector<int>>& triangle,int curr_row,int curr_col,int row,vector<vector<int>> &dp){
    if(curr_row  == row -1 ){
        return triangle[curr_row][curr_col];
    }

    if(dp[curr_row][curr_col] != INT_MAX){
        return dp[curr_row][curr_col];
    }
   

  
        int bottom = triangle[curr_row][curr_col]+min_path(triangle,curr_row+1,curr_col,row,dp);
    
    
        int bottom_right = triangle[curr_row][curr_col]+min_path(triangle,curr_row+1,curr_col+1,row,dp);
    
    return  dp[curr_row][curr_col] = min(bottom,bottom_right);

}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));

        return min_path(triangle,0,0,n,dp);
    }
};