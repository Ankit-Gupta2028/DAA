class Solution {
int LCS(int index1,int index2,string &str1, string &str2,vector<vector<int>> &dp){
        if(index1 < 0 || index2 < 0){
            
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        int Equal = 0;
        int Not_Equal = 0;
        if(str1[index1] == str2[index2]){
            Equal = 1+LCS(index1-1,index2-1,str1,str2,dp);
        }else{
            int first = LCS(index1-1,index2,str1,str2,dp);
            int  second = LCS(index1,index2-1,str1,str2,dp);

            Not_Equal = max(first,second);
        }
        return dp[index1][index2] = max(Equal,Not_Equal);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int s1 = text1.size();
        int s2 = text2.size();

        vector<vector<int>> dp(s1,vector<int>(s2,-1));

        return LCS(s1-1,s2-1,text1,text2,dp);
    }
};