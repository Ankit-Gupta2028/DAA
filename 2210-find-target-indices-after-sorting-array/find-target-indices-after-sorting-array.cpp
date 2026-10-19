class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int less_than_target = -1;
        int total_tar = 0;

        for(int i=0;i<n;i++){
            if(nums[i] < target){
                less_than_target +=1;
            }
            if(nums[i] == target){
                total_tar +=1;
            }
        }

        
        for(int i=0;i<total_tar;i++){
            less_than_target+=1;
            ans.push_back(less_than_target);
        }
        return ans;
    }
};