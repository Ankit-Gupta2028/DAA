class Solution {
int max_sum(vector<int>& nums,int n,vector<int> &dp){

    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int pick = nums[n]+max_sum(nums,n-2,dp);
    int not_pick = 0+max_sum(nums,n-1,dp);

    dp[n] = max(pick,not_pick);

    return max(pick,not_pick);

}
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,-1);
        return max_sum(nums,n-1,dp);
    }
};