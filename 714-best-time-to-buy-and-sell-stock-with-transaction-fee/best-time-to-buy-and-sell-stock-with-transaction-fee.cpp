class Solution {
int max_profit(int buy,int index ,int &n,vector<int> &arr,vector<vector<int>> &dp,int &fee){

    if(index == n ){
        return 0;
    }
    if(dp[index][buy] != -1){
        return dp[index][buy];
    }
    int profit = 0;

    if(buy == 0){
        profit = max(0+max_profit(0,index+1,n,arr,dp,fee), 
        (-1)*arr[index]+max_profit(1,index+1,n,arr,dp,fee));
    }

    if(buy == 1){
        profit = max(0 + max_profit(1,index+1,n,arr,dp,fee),
        arr[index]-fee+max_profit(0,index+1,n,arr,dp,fee));
    }

    return dp[index][buy]=profit;


}
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = max_profit(0,0,n,prices,dp,fee);
        return ans;
    }
};