class Solution {
    int module = INT_MAX;

public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(N,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
             if(i%coins[0] == 0){
                dp[0][i] = 1;
            }
        }
         for(int i=0;i<N;i++){
            dp[i][0]= 1;
        }

        

        for(int i=1;i<N;i++){
            for(int amt = 1; amt<= amount;amt++){
                long long  not_take = dp[i-1][amt];
                long long take = 0;
                if(coins[i] <= amt){
                    take = dp[i][amt-coins[i]];
                }
                dp[i][amt] = (take + not_take)%module;
            }
        }
        return dp[N-1][amount];
       

    }
};