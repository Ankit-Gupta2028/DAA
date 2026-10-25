class Solution {
void nextPermutations(int ind,vector<int>&nums, vector<vector<int>> &ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }
    set<int> st;
    for(int i=ind;i<nums.size();i++){

        if(st.find(nums[i]) != st.end()){
            continue;
        }
            st.insert(nums[i]);
       
            swap(nums[i],nums[ind]);
            nextPermutations(ind+1,nums,ans);
            swap(nums[i],nums[ind]);

    }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        nextPermutations(0,nums,ans);
       
        return ans;
    }
};