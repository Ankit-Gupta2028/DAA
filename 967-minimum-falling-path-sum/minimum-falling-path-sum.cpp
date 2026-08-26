class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m,INT_MAX);

        for(int i=0;i<m;i++){
            dp[i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            vector<int> temp(m,INT_MAX);
            for(int j=0;j<m;j++){

                
                int up_left = INT_MAX;
                int up_right = INT_MAX;

               
                int up = matrix[i][j]+dp[j];
                
                if( j+1 < m){
                    up_right = matrix[i][j]+dp[j+1];
                }
                if( j-1 >=0){
                    up_left = matrix[i][j]+dp[j-1];
                }
                temp[j] = min(up,min(up_left,up_right));
                
            }
            dp = temp;
   
        }

        int ans = INT_MAX;

        for(int i=0;i<m;i++){
            ans = min(ans,dp[i]);
        }


        return ans;
    }
};