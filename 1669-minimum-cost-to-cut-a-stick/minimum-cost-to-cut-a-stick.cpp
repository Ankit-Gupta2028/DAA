class Solution {
int Minimum_cost_to_cut_the_stick(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){

    if(i > j){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = INT_MAX ;
    for(int k=i;k<=j;k++){

        int ans = (cuts[j+1] - cuts[i-1]) + Minimum_cost_to_cut_the_stick(i,k-1,cuts,dp)+ Minimum_cost_to_cut_the_stick(k+1,j,cuts,dp);

        mini = min(ans,mini);
    }
    return dp[i][j]=mini;
}
public:
    int minCost(int n, vector<int>& cuts) {
       
        int N = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(N+2,vector<int>(N+2,-1));

       return Minimum_cost_to_cut_the_stick(1,N,cuts,dp);

    }
};