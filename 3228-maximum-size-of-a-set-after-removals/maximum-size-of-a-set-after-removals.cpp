class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> s1;
        unordered_set<int> s2;
        int common = 0;

        for(int i=0;i<n;i++){
            s1.insert(nums1[i]);
            s2.insert(nums2[i]);
        }

        for (auto &x:s1 ) {

            if (s2.find(x) != s2.end()) {
                common += 1;
            }
 
        }

        if(common == n){
            return n;
        }
        int unique1 = s1.size() - common;
        int unique2 = s2.size() - common;

        int take_unique1 = min(unique1,n/2);
        int take_unique2 = min(unique2,n/2);

        int remaining = n - (take_unique1+take_unique2);

        int take_rem = min(remaining,common);

        return take_unique1+take_unique2+take_rem;


        
        
        
    }
};