class Solution {
    int module = INT_MAX;
    int possible(int index,vector<int>&coins, int amount,vector<vector<int>> &dp){
        
        if(amount == 0){
            return 1;
        }
        
        if(index == 0){
            if(amount%coins[0] == 0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int not_take = possible(index-1,coins,amount,dp);
        int take = 0;
        if(coins[index] <= amount){
            take = possible(index,coins,amount-coins[index],dp);
        }
        return dp[index][amount] = (take + not_take)%module;
    }
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(N,vector<int>(amount+1,-1));

        return possible(N-1,coins,amount,dp);
    }
};