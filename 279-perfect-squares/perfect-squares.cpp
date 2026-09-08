class Solution {
int least_num( int index,vector<vector<int>> &dp,int target){
    if( target == 0){
        return 0;
    }
    if(index == 1){
        
        return target;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    int not_take = least_num(index-1,dp,target);
    int take = 1e9;
    int square = index*index;
    if(target >= square){
        take = 1+least_num(index,dp,target-square);
    }
    return dp[index][target] = min(take,not_take);
}
public:
    int numSquares(int n) {
        

        int N = sqrt(n);
        vector<vector<int>> dp(N+1,vector<int>(n+1,1e9));

        for(int index = 0; index <= N; index++) {
            dp[index][0] = 0;
        }

        
        for(int target = 1; target <= n; target++) {
            dp[1][target] = target;
        }

        for(int index = 2; index <= N; index++){
            for(int target = 1; target <= n; target++){
                int not_take = dp[index-1][target];

                int take = 1e9;
                int square = index*index;
                if(target >= square){
                    take = 1+dp[index][target-square];
                }
                
                 dp[index][target] = min(take,not_take);
            }
        }

      

        return dp[N][n];

    }
};