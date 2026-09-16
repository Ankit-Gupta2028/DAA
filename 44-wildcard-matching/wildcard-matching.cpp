class Solution {
bool Wildcard_matching(int index1,int index2,string &str, string &pat, vector<vector<int>> &dp){
    if(index1 < 0 && index2 < 0){
        return true;
    }
    if(index1 >= 0 && index2 < 0){
        return false;
    }
    if(index1 < 0 && index2 >=0){
        while(index2 >=0){
            if(pat[index2] != '*'){
                return false;
            }
            index2--;
        }

        return true;
    }
    

    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }
    if(str[index1] == pat[index2] || pat[index2] == '?'){
        return dp[index1][index2]=Wildcard_matching(index1-1,index2-1,str,pat,dp);
    }
    else if(pat[index2] == '*'){
        return dp[index1][index2] = Wildcard_matching(index1-1,index2,str,pat,dp) || Wildcard_matching(index1,index2-1,str,pat,dp); 
    }else{
        return dp[index1][index2] = false;
    }
}
public:
    bool isMatch(string s, string p) {
        int index1 = s.size();
        int index2 = p.size();

        vector<vector<int>> dp(index1,vector<int>(index2,-1));

        return Wildcard_matching(index1-1,index2-1,s,p,dp);

    }
};