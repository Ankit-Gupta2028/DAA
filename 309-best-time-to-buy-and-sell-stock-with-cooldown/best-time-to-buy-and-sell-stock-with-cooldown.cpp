class Solution {

public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();

        vector<int> dp(2,0);

        vector<int> curr1(2,0);
        vector<int> curr2(2,0);

        for(int i=n-1;i>=0;i--){
            

                dp[1] = max(curr1[1],(-1)*prices[i]+curr1[0]);
                    
                dp[0] = max(prices[i]+curr2[1],curr1[0]);

                curr2 = curr1;
                curr1 = dp;
               
                      
            
        }
        return dp[1];
    }
};