class Solution {
bool equal_subset(int index, vector<int> &arr,int n, vector<vector<int>> &dp, int k) {
    if(k==0){
        return true;
    }
    if(index == n){
        return false;
    }
    if(dp[index][k] != -1){
        return dp[index][k];
    }

    int take = false;
    if(arr[index] <= k){
        take = equal_subset(index+1,arr,n,dp,k-arr[index]);
    }

    int not_take = equal_subset(index+1,arr,n,dp,k);

    return dp[index][k] = take || not_take;
    
}
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
         if(n == 1){
            return false;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum +=  nums[i];
        }
        if(sum % 2 == 1 ){
            return false;
        }
        int k = sum /2;

        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        return equal_subset(0, nums,n,dp,k);

    }
};