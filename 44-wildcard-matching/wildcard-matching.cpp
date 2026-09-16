class Solution {

public:
    bool isMatch(string s, string p) {
 
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        

        dp[0][0] = 1;
        for(int index2=1;index2<=m;index2++){
            int flag = true;
            for(int i=1; i<=index2;i++ ){
            if(p[i-1] != '*'){
                flag = false;
            }
            }
            dp[0][index2] = flag;
        }
        for(int index1=1;index1<=n;index1++){
            for(int index2=1;index2<=m;index2++){
                if(s[index1-1] == p[index2-1] || p[index2-1] == '?'){
                    dp[index1][index2]=dp[index1-1][index2-1];
                }else if(p[index2-1] == '*'){
                    dp[index1][index2] = dp[index1-1][index2] || dp[index1][index2-1]; 
                }else{
                    dp[index1][index2] = false;
                }
            }
        }

        return dp[n][m];


    }
};