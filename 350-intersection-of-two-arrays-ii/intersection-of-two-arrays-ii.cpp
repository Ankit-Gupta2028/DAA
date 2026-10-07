class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
         vector<int>  ans;

        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]+=1;
        }
        for(int i=0;i<nums2.size();i++){
            if(m1.find(nums2[i]) != m1.end() && m1[nums2[i]] > 0){
                m1[nums2[i]]-=1;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};