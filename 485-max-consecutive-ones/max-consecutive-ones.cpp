class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int n = nums.size();

        int max_ones = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                count +=1;
                max_ones = max(count,max_ones);
            }else{
                count = 0;
            }
        }
        return max_ones;
    }
};