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
    int Target = (total_sum - target)/2;
   vector<int> dp(Target+1,0);

    

    if(nums[0]==0){
        dp[0]=2;
    }else{
        dp[0]=1;
    }
    if(nums[0]<=Target && nums[0] != 0){
        dp[nums[0]]=1;
    }

    for(int i=1;i<n;i++){
        vector<int> temp(Target+1,0);
        for(int target1=0;target1<=Target;target1++){
            int not_take = dp[target1];
            int take =0;

        if(nums[i] <= target1){
               take=dp[target1-nums[i]];
        }
        temp[target1] = (take+not_take)%module;
     
        }
        dp=temp;

    }


    return dp[Target];
    }
};