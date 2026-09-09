class Solution {
int longest_incr_sub(int index,int prev_index,vector<int>& nums,vector<vector<int>> &dp){
   
    if(index == nums.size()-1 ){
        if(prev_index == -1 || nums[index] > nums[prev_index]){
            return 1;
        }
       
        return 0;
    }
    if(dp[index][prev_index+1] != -1){
        return dp[index][prev_index+1];
    }
    int not_take = 0+longest_incr_sub(index+1,prev_index,nums,dp);

    int take = 0;

    if(prev_index == -1 ){
        take = longest_incr_sub(index+1,index,nums,dp)+1;
    }else if(nums[index] > nums[prev_index]){
        take = longest_incr_sub(index+1,index,nums,dp)+1;
    }
    
    return dp[index][prev_index+1] = max(take,not_take);
}
public:
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
      vector<vector<int>> dp(n, vector<int>(n+1,-1) );

      return longest_incr_sub(0,-1,nums,dp);
    }
};