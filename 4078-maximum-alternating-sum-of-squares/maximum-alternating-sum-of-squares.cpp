class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int i=0;
        int j = n-1;
       long long right_side = 0;
       long long leftside = 0;
        long long ans = 0;
        while(i < j){
           right_side += (nums[j] * nums[j]);
            leftside += (nums[i] * nums[i]);
            i++;
            j--;
        }
        ans += right_side- leftside;
        if(n%2 == 0){
            return ans;
        }
        ans += (nums[i]*nums[i]);
        return ans;
    }
};