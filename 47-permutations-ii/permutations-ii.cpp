class Solution {
void nextPermutations(int ind,vector<int>&nums, set<vector<int>> &st){
    if(ind == nums.size()){
        st.insert(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
       
            swap(nums[i],nums[ind]);
            nextPermutations(ind+1,nums,st);
            swap(nums[i],nums[ind]);
        
        


    }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        nextPermutations(0,nums,st);
        for(auto &it : st){
            ans.push_back(it);
        }
        return ans;
    }
};