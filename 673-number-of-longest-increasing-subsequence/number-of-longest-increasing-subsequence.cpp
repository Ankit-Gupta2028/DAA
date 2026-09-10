class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
                int n = nums.size();
        
        vector<int> dp (n,1) ;
        vector<int> count (n,1) ;
        int Max_len = 1;
        int ans = 0;


        for(int i=0;i<n;i++){
            int index = i-1;
            while(index >=0){
                if(nums[i] > nums[index]){
                    if(dp[i] < dp[index]+1){
                        dp[i]=dp[index]+1;
                        count[i]=count[index];
                    }else if(dp[i] == dp[index]+1){
                        count[i]+=count[index];
                    }
                   
                }
                index--;
            }
            Max_len = max(Max_len,dp[i]);
            
        }
        for(int i=0;i<n;i++){
            if(dp[i] == Max_len){
                ans += count[i];
            }
        }
        return ans;
    }
};