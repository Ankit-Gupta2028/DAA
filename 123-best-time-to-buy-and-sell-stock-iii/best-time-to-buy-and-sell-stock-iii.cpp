class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                for(int no_times_buy=1;no_times_buy<=2;no_times_buy++){

                    if(buy == 0){
                         dp[i][buy][no_times_buy]=max(0+dp[i+1][0][no_times_buy],
                         (-1)*prices[i]+dp[i+1][1][no_times_buy]
                         );
                    }else{
                        dp[i][buy][no_times_buy] = max(0+dp[i+1][1][no_times_buy],prices[i]+dp[i+1][0][no_times_buy-1]);
                    }
                   
                }
            }
        }
        return dp[0][0][2];
    }
};