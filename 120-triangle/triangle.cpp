class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {

         int n = triangle.size();
        int m = triangle[n-1].size();

      vector<int> dp(n,0);

        for(int i=0;i<n;i++){
            dp[i] = triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){

            vector<int> temp(n,0);

            for(int j=i;j>=0;j--){
                int bottom = triangle[i][j] + dp[j];
                int bottom_right = triangle[i][j] + dp[j+1];

                temp[j]= min(bottom,bottom_right);
            }
            dp = temp;

        }
        return dp[0];
        
        
    }
};