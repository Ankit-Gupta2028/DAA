class Solution {

public:
    string shortestCommonSupersequence(string str1, string str2) {
         int s1 = str1.size();
        int s2 = str2.size();

        vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));
       

        for(int index1=1;index1<=s1;index1++){
            for(int index2=1;index2<=s2;index2++){
                
                
                if(str1[index1-1] == str2[index2-1]){
                    dp[index1][index2] = 1+dp[index1-1][index2-1];
                }else{
                    int first = dp[index1-1][index2];
                    int  second = dp[index1][index2-1];
                     dp[index1][index2] = max(first,second);
                }
                
            }

        }

        int i = s1;
        int j = s2;

        string SCS;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                SCS+=str1[i-1];
                i = i-1;
                j = j-1;
                
            }else if(dp[i-1][j] > dp[i][j-1]){
                 SCS+=str1[i-1];
                i = i-1;
            }else{
                 SCS+=str2[j-1];
                j = j-1;
            }
        }

        while(i > 0 ){
            SCS+=str1[i-1];
            i--;
        }
        while(j > 0 ){
            SCS+=str2[j-1];
            j--;
        }

        reverse(SCS.begin(),SCS.end());
        return SCS;

    }
};