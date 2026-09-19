class Solution {
bool ispalindrome(int i,int j,string &s){

    while(i <= j){
        if(s[i] != s[j]){
            return false;
           
        }
        i++;
        j--;
    }
    return true;
}

public:
    int minCut(string s) {
            		
        int n = s.size();
       vector<int> dp(n+1,0);
        
        for(int i = n-1;i>=0;i--){
                int mini = INT_MAX;

            for(int k=i;k<=n-1;k++){
                if(ispalindrome(i,k,s)){
                int ans = 1  + dp[k+1];
                mini = min(ans,mini);
                }
       
            }
             dp[i]=mini;
        }
        
        return dp[0] - 1;
    }
};