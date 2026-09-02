class Solution {
int Max_profit(int buy,int index ,int no_times_buy,int &n,vector<int> &arr,vector<vector<vector<int>>> &dp,int &k){

    if(index == n || no_times_buy > k){
        return 0;
    }
    if(dp[index][buy][no_times_buy] != -1){
        return dp[index][buy][no_times_buy];
    }
    int profit = 0;

    if(buy == 0){
        profit = max(0+Max_profit(0,index+1,no_times_buy,n,arr,dp,k), 
        (-1)*arr[index]+Max_profit(1,index+1,no_times_buy+1,n,arr,dp,k));
    }

    if(buy == 1){
        profit = max(0 + Max_profit(1,index+1,no_times_buy,n,arr,dp,k),
        arr[index]+Max_profit(0,index+1,no_times_buy,n,arr,dp,k));
    }

    return dp[index][buy][no_times_buy]=profit;


}
public:
    int maxProfit(int k, vector<int>& prices) {


        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        int ans = Max_profit(0,0,0,n,prices,dp,k);
        return ans;
        
    }
};