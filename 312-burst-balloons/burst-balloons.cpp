class Solution {
int Burst_balloons(int i,int j,vector<int>& nums,  vector<vector<int>> &dp){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int maxi = INT_MIN;

    for(int k=i;k<=j;k++){
        int ans = (nums[i-1]*nums[k]*nums[j+1]) + Burst_balloons(k+1,j,nums,dp) +Burst_balloons(i,k-1,nums,dp);

        maxi = max(ans,maxi);
    }
    return dp[i][j] = maxi;
}
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        return Burst_balloons(1,n,nums,dp);

    }
};