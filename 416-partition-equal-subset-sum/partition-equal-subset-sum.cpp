class Solution {

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

       
        if(n == 1){
            return false;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 == 1 ){
            return false;
        }
        int k = sum /2;

        vector<int> dp(k+1,0);

        dp[0]=1;

        for(int i= n-1;i>=0;i--){
            vector<int> temp(k+1,0);
            temp[0]=1;

            for(int target=0;target<=k;target++){
                int not_take = dp[target];

                int take = false;
                if(nums[i] <= target){
                    take = dp[target-nums[i]];
                }
                temp[target] = take || not_take;
            }
            dp = temp;
        }

        return dp[k];


    }
};