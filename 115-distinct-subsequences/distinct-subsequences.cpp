class Solution {
        int modeule = 1e9 + 7;

public:
    int numDistinct(string s, string t) {
       int index1 = s.size();
       int index2 = t.size();

       vector<vector<int>> dp(index1+1,vector<int>(index2+1,0));

        for(int i=0;i<=index1;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=index2;i++){
            dp[0][i] = 0;
        }
       
        for(int i=1;i<=index1;i++){
            for(int j = 1;j<=index2;j++){

                if(s[i-1] == t[j-1]){

                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % modeule;

                }else{

                    dp[i][j] = dp[i-1][j];

                }
            }
        }
        return dp[index1][index2];

    }
};