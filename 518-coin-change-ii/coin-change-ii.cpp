class Solution {
    int module = INT_MAX;

public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<long long> dp(amount+1,0);
         

        for(int i=0;i<=amount;i++){
             if(i%coins[0] == 0){
                dp[i] = 1;
            }
        }
        
        dp[0]= 1;
        

        

        for(int i=1;i<N;i++){
               vector<long long> temp(amount+1,0);
                temp[0]= 1;
            for(int amt = 1; amt<= amount;amt++){
                long long not_take = dp[amt];
                long long take = 0;
                if(coins[i] <= amt){
                    take = temp[amt-coins[i]];
                }
                temp[amt] = (take + not_take)%module;
            }
            dp = temp;
        }
        return dp[amount];
       

       

    }
};