class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            long long MAX=INT_MIN;
            long long MIN=INT_MAX;
            for(int j=i;j<n;j++){

                MAX=max(MAX,(long long)nums[j]);
                MIN=min(MIN,(long long)nums[j]);
                sum=sum+(MAX-MIN);
            }

        }
        return sum;
    }
};