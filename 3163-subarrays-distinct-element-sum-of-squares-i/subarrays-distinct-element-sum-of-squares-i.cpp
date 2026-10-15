class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        


        for(int i=0;i<n;i++){
            unordered_set<int> s1;
            for(int j=i;j<n;j++){
                s1.insert(nums[j]);
                int curr = s1.size();
                ans += curr*curr;
            }
            
        }
        
        return ans;
    }
};