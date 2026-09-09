class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        return 0;
        vector<int> dp (n+1,0) ;

        for(int i=-1;i<n;i++){
            if( i== -1 || nums[n-1] > nums[i] ){
                dp[i+1] = 1;
            }
        }

        for(int index=n-2; index>=0;index--){
            vector<int> temp (n+1,0) ;
            for(int prev_index = -1;prev_index<n;prev_index++){
                int not_take = dp[prev_index+1];

                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index]){
                    take = 1+ dp[index+1];
                }
                temp[prev_index+1] = max(not_take,take);

            }
            dp = temp;
        }


      return dp[0];
    }
};