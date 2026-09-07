class Solution {
    int module = 1e9+7;
int possible(int index,vector<int>&arr, int target,vector<vector<int>> &dp){

    
    if(index == 0){
        if(target == 0 && arr[0]==0){
            return 2;
        }
        if(target == 0 || arr[0]==target){
            return 1;
        }
        return 0;
      
    }

    if(dp[index][target] != -1){
        
        return dp[index][target] ;
    }
    int not_take = possible(index-1,arr,target,dp);

    int take = 0;
    if(arr[index] <= target){
        take = possible(index-1,arr,target - arr[index],dp);
    }

    return dp[index][target] = (take + not_take)%module;

}
public:
    int findTargetSumWays(vector<int>& nums, int target) {

    int n = nums.size();
    int total_sum = 0;
    for(auto& num:nums){
        total_sum+=num;
    }
    int Target = (total_sum-target)/2;

    if(total_sum - target < 0){
        return 0;
    }

    if((total_sum - target)%2 == 1){
        return 0;
    }

    vector<vector<int>> dp(n,vector<int>(Target+1,-1));

    return possible(n-1,nums,Target,dp);
    }
};