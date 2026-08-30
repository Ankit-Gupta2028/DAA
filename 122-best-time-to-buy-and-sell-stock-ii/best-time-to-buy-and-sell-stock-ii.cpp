class Solution {
int max_profit(vector<int> &arr,int n, vector<int> &dp){

    for(int i=n-1;i>=0;i--){
        vector<int> temp(2,0);
        for(int buy = 0;buy<=1;buy++){
            int profit = 0;
            if(buy == 0){
                profit = max((-1)*arr[i]+dp[buy+1],dp[buy]);
            }else{
                profit = max(arr[i]+dp[buy-1],dp[buy]);
            }
            temp[buy]=profit;
        }
        dp = temp;
    }
    return  dp[0];
} 
public:
    int maxProfit(vector<int>& prices) {

        vector<int> dp(2,0);
        int n = prices.size();

        return max_profit(prices,n,dp);
    }
};