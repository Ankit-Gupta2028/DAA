class Solution {

public:
    int minDistance(string word1, string word2) {
        
        int index1 = word1.size();
        int index2 = word2.size();

      

        vector<vector<int>> dp(index1+1,vector<int>(index2+1,0));

        for(int i=0;i<=index2;i++){
            dp[0][i] = i;
        }
         for(int i=0;i<=index1;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=index1;i++){
            for(int j=1;j<=index2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }else{
                dp[i][j] =  1 + 
                min(dp[i-1][j],min(dp[i-1][j-1],
                dp[i][j-1]));
                }
            }
        }
        return dp[index1][index2];
         
    }
};