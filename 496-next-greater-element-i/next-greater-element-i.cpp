class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
       unordered_map<int,int> m1;
       
       stack<int> s1;
       for(int i=nums2.size()-1;i>=0;i--){
           
            while(!s1.empty() && s1.top()<=nums2[i]){
                s1.pop();
                
            }
            if(!s1.empty()){
                m1[nums2[i]]=s1.top();
            }else{
                m1[nums2[i]]= -1;
            }
            s1.push(nums2[i]);
       }
        vector<int> ans;
       for(int i=0;i<nums1.size();i++){
            ans.push_back(m1[nums1[i]]);
       }
       return ans;
       
    }
};