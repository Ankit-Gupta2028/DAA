class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s1;
        vector<int> ans(n,-1);

        for(int i=(2*n)-1;i>=0;i--){
            int index=i%n;
            int curr=nums[index];
            while(!s1.empty() && s1.top()<=curr){
                s1.pop();
            }
            if(i<n){
                if(!s1.empty()){
                    ans[i]=s1.top();
                }
            }
            s1.push(curr);
        }
        return ans;
    }
};