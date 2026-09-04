class Solution {

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

       if(n == 1){
            return false;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum +=  nums[i];
        }
        if(sum % 2 == 1 ){
            return false;
        }
        int k = sum /2;

        vector<vector<int>> dp(n+1,vector<int>(k+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i= n-1;i>=0;i--){

            for(int target=0;target<=k;target++){
                int not_take = dp[i+1][target];

                int take = false;
                if( nums[i] <= target){
                    take= dp[i+1][target - nums[i]];
                }
                dp[i][target] = take || not_take;
            }
        }

        return dp[0][k];

    }
};