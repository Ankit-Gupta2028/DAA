class Solution {
int least_num( int index,vector<int> &nums,vector<vector<int>> &dp,int target){
    if( target == 0){
        return 0;
    }
    if(index == 0){
        if(target % nums[0] == 0){
            return target / nums[0];
        }
        return 1e9;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    int not_take = least_num(index-1,nums,dp,target);
    int take = 1e9;
    if(target >= nums[index]){
        take = 1+least_num(index,nums,dp,target-nums[index]);
    }
    return dp[index][target] = min(take,not_take);
}
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            int x = sqrt(i);
            if(x*x == i){
                nums.push_back(i);
            }
        }

        int N = nums.size();
        vector<vector<int>> dp(N,vector<int>(n+1,0));

        for(int i=0;i<=n;i++){
            if(i % nums[0] == 0){
                dp[0][i]= i / nums[0];
            }else{
                dp[0][i]=1e9;
            }
        }

        for(int index = 1;index<N;index++){
            for(int target = 0;target<=n;target++){
                int not_take = dp[index-1][target];

                 int take = 1e9;
                 if(target >= nums[index]){
                    take = 1+ dp[index][target - nums[index]];
                }

                dp[index][target] = min(take ,not_take);
            }
        }
        return dp[N-1][n];

        

    }
};