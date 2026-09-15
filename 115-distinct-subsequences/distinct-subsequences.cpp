class Solution {
    int modeule = 1e9 + 7;
    int Distinct_subsequences(string &s, string &t,int index1,int index2,vector<vector<int>> &dp){

        if(index2 < 0){
            return 1;
        }
        if(index1 < 0){
            return 0;
        }
        if(index2 == 0 ){
            int count = 0;
           for(int i=index1;i>=0;i--){
            if(t[0] == s[i]){
                count+=1;
            }
           }
           return count;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        int match = 0;
        int not_match = 0;
        
        if(s[index1] == t[index2]){
            match = Distinct_subsequences(s,t,index1-1,index2-1,dp);
            not_match = Distinct_subsequences(s,t,index1-1,index2,dp);
            return dp[index1][index2] = (match+not_match) %modeule;
        }
        return dp[index1][index2] = Distinct_subsequences(s,t,index1-1,index2,dp);
        

        
    }
public:
    int numDistinct(string s, string t) {
        int s1 = s.size();
       int s2 = t.size();

       vector<vector<int>> dp(s1,vector<int>(s2,-1));

       return Distinct_subsequences(s,t,s1-1,s2-1,dp);
    }
};