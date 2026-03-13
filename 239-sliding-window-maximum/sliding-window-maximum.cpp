class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> d1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!d1.empty() && d1.front()<= i-k){
                d1.pop_front();
            }
            while(!d1.empty() && nums[d1.back()]<=nums[i]){
                d1.pop_back();
            }
            d1.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[d1.front()]);
            }
        }
        return ans;
    }
};