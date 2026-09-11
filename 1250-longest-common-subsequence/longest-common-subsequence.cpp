class Solution {

public:
    int longestCommonSubsequence(string text1, string text2) {
        
       int s1 = text1.size();
        int s2 = text2.size();

        vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));

        for(int index1=1;index1<=s1;index1++){
            for(int index2=1;index2<=s2;index2++){
                int Equal = 0;
                int Not_Equal = 0;
                if(text1[index1-1] == text2[index2-1]){
                    Equal = 1+dp[index1-1][index2-1];
                }else{
                    int first = dp[index1-1][index2];
                    int  second = dp[index1][index2-1];
                     Not_Equal = max(first,second);
                }
                dp[index1][index2] = max(Equal,Not_Equal);
            }

        }
        return dp[s1][s2];
    }
};