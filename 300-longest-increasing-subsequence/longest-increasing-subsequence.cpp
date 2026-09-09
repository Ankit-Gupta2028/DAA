class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp (n,1) ;
        int ans = 1;

        for(int i=0;i<n;i++){
            int index = i-1;
            while(index >=0){
                if(nums[i] > nums[index]){
                    dp[i] = max(dp[i],dp[index]+1);
                    ans = max(ans,dp[i]);
                }
                index--;
            }
        }
        return ans;
    }
};