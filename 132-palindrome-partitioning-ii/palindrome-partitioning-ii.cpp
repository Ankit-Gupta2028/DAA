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
int Palindrome_partitioning_II(int i,int j,string &s,vector<int> &dp){
    if(i > j){
        return 0;
    }
    if(ispalindrome(i,j,s)){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int mini = INT_MAX;

    for(int k=i;k<=j;k++){
        if(ispalindrome(i,k,s)){
              int ans = 1  + Palindrome_partitioning_II(k+1,j,s,dp);
               mini = min(ans,mini);
        }
       
    }
    return dp[i]=mini;
}
public:
    int minCut(string s) {
            		
         int n = s.size();
       vector<int> dp(n,-1);
        
        
        return Palindrome_partitioning_II(0,n-1,s,dp);
    }
};