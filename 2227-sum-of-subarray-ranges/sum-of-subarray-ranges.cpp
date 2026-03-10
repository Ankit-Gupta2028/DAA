class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
      
        long long sum=0;

        for(int i=0;i<nums.size();i++){
            long long MAX=nums[i];
            long long MIN=nums[i];
            for(int j=i+1;j<nums.size();j++){

                MAX=max(MAX,(long long)nums[j]);
                MIN=min(MIN,(long long)nums[j]);
                sum=sum+(MAX-MIN);
            }
        }
        return sum;
    }
};