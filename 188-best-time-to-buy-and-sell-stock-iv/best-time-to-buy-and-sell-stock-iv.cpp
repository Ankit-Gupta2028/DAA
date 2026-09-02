class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(k+1,0));
         vector<vector<int>> temp(2,vector<int>(k+1,0));
      
        for(int i= n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int no_times_buy=1;no_times_buy<=k;no_times_buy++){

                    if(buy == 0){
                        temp[buy][no_times_buy]=max(0+dp[0][no_times_buy],(-1)*prices[i]+dp[1][no_times_buy]);
                    }else{
                        temp[buy][no_times_buy]= max(0+dp[1][no_times_buy],prices[i]+dp[0][no_times_buy-1]);
                    }
                }
                dp = temp;
            }
        }
        return dp[0][k];
    }
};