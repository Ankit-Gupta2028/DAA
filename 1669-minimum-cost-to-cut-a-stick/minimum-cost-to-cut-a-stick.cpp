class Solution {
int Minimum_cost_to_cut_the_stick(int i,int j,int start_wood,int end_wood,vector<int>& cuts,vector<vector<int>> &dp){

    if(i > j){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = INT_MAX ;
    for(int k=i;k<=j;k++){

        int ans = (end_wood - start_wood) + Minimum_cost_to_cut_the_stick(i,k-1,start_wood,cuts[k],cuts,dp)+ Minimum_cost_to_cut_the_stick(k+1,j,cuts[k],end_wood,cuts,dp);

        mini = min(ans,mini);
    }
    return dp[i][j]=mini;
}
public:
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(N,vector<int>(N,-1));

       return Minimum_cost_to_cut_the_stick(0,N-1,0,n,cuts,dp);

    }
};