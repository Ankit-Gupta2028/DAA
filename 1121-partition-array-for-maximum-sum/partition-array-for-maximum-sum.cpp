class Solution {


public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int maxi = INT_MIN;
            int curr_max = INT_MIN;
            for(int m = i;m<min((int)arr.size(),i+k);m++){
                curr_max = max(arr[m],curr_max);
                if((m-i)+1 <= k){
                int ans = (curr_max * ((m-i)+1)) + dp[m+1];

                maxi = max(maxi,ans);
                }
            }
            dp[i] = maxi;
        }

        return dp[0];

    }
};