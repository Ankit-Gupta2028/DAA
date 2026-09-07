class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       vector<int> dp(amount+1,0);

        for(int i=0;i<=amount;i++){
            if((i % coins[0]) == 0){
                  dp[i] = i/coins[0];
            }else{
                dp[i] = 1e9;
            }
            
        }
        vector<int> temp(amount+1,0);
       

        for(int index=1;index<n;index++){
             
            for(int amt=0;amt<=amount;amt++){
                int not_take = 0 + dp[amt];
                int take = 1e9;

                if(amt >= coins[index]){
                    take = 1+temp[amt-coins[index]];
                }

                temp[amt] = min(take,not_take);
            }
            dp = temp;
        }


        if(dp[amount] == 1e9){
            return -1;
        }
        return dp[amount];
    }
};