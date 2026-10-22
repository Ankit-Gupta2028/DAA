class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<long long,long long> m1;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){

                m1[nums1[i] + nums2[j]] +=1;
 
            }
        }
        int ans = 0;
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){

                if(m1.find(-(nums3[i] + nums4[j])) != m1.end() ){
                    ans+= m1[-(nums3[i] + nums4[j])];
                }
 
            }
        }
        return ans;

    }
};