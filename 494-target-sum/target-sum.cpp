class Solution {
    int module = 1e9+7;

public:
    int findTargetSumWays(vector<int>& nums, int target) {

    int total_sum = 0;
    int n = nums.size();

    for(int i=0;i<n;i++){
        total_sum+=nums[i];
    }
     if(total_sum-abs(target) < 0 || (total_sum-target) % 2 != 0){
        return 0;
    }
    vector<vector<int>> dp(n,vector<int>(total_sum+1,0));

    int Target = (total_sum - target)/2;

    if(nums[0]==0){
        dp[0][0]=2;
    }else{
        dp[0][0]=1;
    }
    if(nums[0]<=Target && nums[0] != 0){
        dp[0][nums[0]]=1;
    }

    for(int i=1;i<n;i++){
        for(int target1=0;target1<=Target;target1++){
            int not_take = dp[i-1][target1];
            int take =0;

        if(nums[i] <= target1){
               take=dp[i-1][target1-nums[i]];
        }
        dp[i][target1] = (take+not_take)%module;
     
        }

    }


    return dp[n-1][Target];

    }
};