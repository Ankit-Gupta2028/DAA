class Solution {
public:
    int uniquePaths(int m, int n) {
       
        vector<int> dp(n,0);
        dp[0]=1;
        int left_past = 1; 
        int ans = 1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up = 0;
                int left = 0;
                if(i==0 && j==0){
                    up = dp[0];
                    left = left_past;
                    
                }else{
                    if(i>0){
                        up = dp[j];
                    } 
                    if(j>0){
                        left = left_past;
                    }
                     ans = left+up;
                    dp[j]=ans;
                    left_past = ans;
                }
                
            }
        }
        return ans;
    }
};