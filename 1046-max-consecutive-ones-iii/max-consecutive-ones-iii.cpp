class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0;
        int left=0;
        int right=0;
        int n=nums.size();
        int max_cons=0;

        while(right<n){
            if(nums[right]==0){
                zero+=1;
            }

            if(zero>k){
                if(nums[left]==0){
                    zero-=1;
                }
                left=left+1;
            }
            if(zero<=k){
                max_cons=max(max_cons,(right-left)+1);
            }
            
            right=right+1;
        }
        return max_cons;
    }
};