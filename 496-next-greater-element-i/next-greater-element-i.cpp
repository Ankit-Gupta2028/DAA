class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
       unordered_map<int,int> m1;
       
       stack<int> s1;
       for(int i=n-1;i>=0;i--){
            int curr=nums2[i];
            while(!s1.empty() && s1.top()<=curr){
                s1.pop();
                
            }
            if(!s1.empty()){
                m1[curr]=s1.top();
            }else{
                m1[curr]= -1;
            }
            s1.push(nums2[i]);
       }
       for(int i=0;i<nums1.size();i++){
            nums1[i]=m1[nums1[i]];
       }
       return nums1;
       
    }
};