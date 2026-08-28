class Solution {

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    dp[n-1][i][j] = grid[n-1][i];
                }
                    
                else{
                     dp[n-1][i][j] =grid[n-1][i] + grid[n-1][j];
                }
                    
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int r1=0;r1<m;r1++){
                for(int r2=0;r2<m;r2++){

                    int maxi = INT_MIN;

                    for(int j1=-1;j1<=1;j1++){
                        for(int j2 =-1; j2<=1;j2++){

                            int ans;
                            if(r1 == r2 ){
                                ans = grid[i][r1];
                            }else{
                                ans =grid[i][r1]+grid[i][r2];
                            }

                            if((r1+j1 < 0 || r1+j1 >= m) || (r2+j2 < 0 || r2+j2 >= m)){
                                ans += -1e9;
                            }else{
                                ans += dp[i+1][r1+j1][r2+j2];
                            }
                            maxi = max(maxi,ans);
                        }
                    }
                    dp[i][r1][r2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];


    }
};