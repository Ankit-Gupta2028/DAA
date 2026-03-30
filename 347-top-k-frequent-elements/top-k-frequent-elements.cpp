class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<>> q1;
         for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }

        for(auto &i : m1){ 
            q1.push({i.second,i.first});
            if(q1.size()>k){
                q1.pop();
            }
            
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(q1.top().second);
            q1.pop();

        }
        return ans;
        
    }
};