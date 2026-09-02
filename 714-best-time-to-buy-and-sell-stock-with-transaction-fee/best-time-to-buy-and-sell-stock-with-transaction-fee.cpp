class Solution {

public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();
        vector<int> dp(2,0);
        vector<int> temp(2,0);
        
        for(int i=n-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                
                if(buy == 0){
                    temp[buy]= max(0+ dp[0],(-1)* prices[i]+dp[1]);
                }else{
                    temp[buy] = max(0 + dp[1], prices[i]-fee+dp[0]);
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};