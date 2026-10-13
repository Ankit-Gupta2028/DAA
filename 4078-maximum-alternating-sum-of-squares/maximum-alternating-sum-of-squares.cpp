class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int i=0;
        int j = n-1;
        long long ans = 0;
        while(i < j){
            ans += (nums[j] * nums[j]);
            ans -= (nums[i] * nums[i]);
            i++;
            j--;
        }
        if(n%2 == 0){
            return ans;
        }
        ans += (nums[i]*nums[i]);
        return ans;
    }
};