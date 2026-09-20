class Solution {
int Partition_Array_for_Maximum_Sum(int i,int j,vector<int>& arr, int k,vector<int> &dp){
    if(i > j){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int maxi = INT_MIN;
    int curr_max = INT_MIN;
    for(int m = i;m<=j;m++){
        curr_max = max(arr[m],curr_max);
        if((m-i)+1 <= k){
            int ans = (curr_max * ((m-i)+1)) + Partition_Array_for_Maximum_Sum(m+1,j,arr,k,dp);

            maxi = max(maxi,ans);
        }
    }
    return dp[i] = maxi;
}

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);

        return Partition_Array_for_Maximum_Sum(0,n-1,arr,k,dp);

    }
};