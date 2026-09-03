class Solution {
int Max_profit(int buy,int index,const vector<int>& arr,int n,vector<vector<int>> &dp){

    if(index >= n){
        return 0;
    }

   
    if(dp[index][buy] != -1){
        return dp[index][buy];
    }
    int profit = 0;
    if(buy == 0){
        profit = max(0 + Max_profit(0,index+1,arr,n,dp),  (-1)*arr[index]+Max_profit(1,index+1,arr,n,dp));
        
    }
    if(buy == 1){
        profit = max(arr[index]+ Max_profit(0,index+2,arr,n,dp), 0+Max_profit(1,index+1,arr,n,dp));
    }
    
    
    return dp[index][buy] = profit;
    
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return Max_profit(0,0,prices,n,dp);
    }
};