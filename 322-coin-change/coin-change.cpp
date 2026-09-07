class Solution {
    int fewest_coin(int index,vector<int>& coins, int amount,vector<vector<int>> &dp){
        if(index == 0){
            if((amount % coins[0]) == 0){
                return amount/coins[0];
            }
            return 1e9;
            
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int not_take = 0+ fewest_coin(index-1,coins,amount,dp);
        int take = 1e9;
        if(amount >= coins[index]){
            take = 1+ fewest_coin(index,coins,amount-coins[index],dp);
        }
        return dp[index][amount] = min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = fewest_coin(n-1,coins,amount,dp);

        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};