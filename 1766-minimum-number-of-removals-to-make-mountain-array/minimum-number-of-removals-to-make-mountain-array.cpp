class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
         int n = nums.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        int ans = 0;

        for(int i=0;i<n;i++){
            int index = i-1;
            while(index >=0){
                if(nums[i] > nums[index] && dp1[i] < dp1[index]+1){
                    dp1[i]=dp1[index]+1;

                }
                index--;
            }
        }
        for(int i=n-1;i>=0;i--){
            int index = i+1;
            while(index != n){
                if(nums[i] > nums[index] && dp2[i] < dp2[index]+1){
                    dp2[i]=dp2[index]+1;

                }
                
                index++;
            }
            if(dp1[i] > 1 && dp2[i] > 1) {
            ans = max(ans, dp1[i] + dp2[i] - 1);
            }
        }
       
        return n-ans;
    }
};