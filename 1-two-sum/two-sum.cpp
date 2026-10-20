class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m1;
        int n = nums.size();

        for(int i=0;i<n;i++){

            int rem = target - nums[i];
            if(m1.find(rem) != m1.end()){
                return {i,m1[rem]};
            }

            m1[nums[i]] = i;

        }
        return {-1,-1};
    }
};