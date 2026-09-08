class Solution {

public:
    int numSquares(int n) {
        

        int N = sqrt(n);
        vector<int> dp(n+1,1e9);
         vector<int> temp(n+1,1e9);

        dp[0] = 0;
        

        
        for(int target = 1; target <= n; target++) {
            dp[target] = target;
        }

        for(int index = 2; index <= N; index++){
            temp[0]=0;
            for(int target = 1; target <= n; target++){
                int not_take = dp[target];

                int take = 1e9;
                int square = index*index;
                if(target >= square){
                    take = 1+temp[target-square];
                }
                
                 temp[target] = min(take,not_take);
            }
            dp = temp;
        }

      

        return dp[n];

    }
};