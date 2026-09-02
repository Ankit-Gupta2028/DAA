class Solution {
int max_profit(int buy,int index ,int no_times_buy,int &n,vector<int> &arr,vector<vector<vector<int>>> &dp){

    if(index == n || no_times_buy > 2){
        return 0;
    }
    if(dp[index][buy][no_times_buy] != -1){
        return dp[index][buy][no_times_buy];
    }
    int profit = 0;

    if(buy == 0){
        profit = max(0+max_profit(0,index+1,no_times_buy,n,arr,dp), 
        (-1)*arr[index]+max_profit(1,index+1,no_times_buy+1,n,arr,dp));
    }

    if(buy == 1){
        profit = max(0 + max_profit(1,index+1,no_times_buy,n,arr,dp),
        arr[index]+max_profit(0,index+1,no_times_buy,n,arr,dp));
    }

    return dp[index][buy][no_times_buy]=profit;


}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans = max_profit(0,0,0,n,prices,dp);
        return ans;
    }
};