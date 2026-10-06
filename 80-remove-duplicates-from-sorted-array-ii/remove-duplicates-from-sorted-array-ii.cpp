class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = 1;
        int j = 0;
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i] == nums[j] && k<2){
                k+=1;
                j++;
                nums[j] = nums[i];
            }else if(nums[i] != nums[j]){
                k=1;
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};