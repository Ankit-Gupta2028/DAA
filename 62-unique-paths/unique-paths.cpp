class Solution {
public:
    int uniquePaths(int m, int n) {
       
        vector<int> dp(n,0);
        dp[0]=1;
        int left_past = 1; 
        int ans = 1;
        
        for(int i=0;i<m;i++){

            vector<int> temp(n,0);

            for(int j=0;j<n;j++){

                int up = 0;
                int left = 0;
                if(i==0 && j==0){
                    temp[j]=1;
                    
                    
                }else{
                    if(i>0){
                        up = dp[j];
                    } 
                    if(j>0){
                        left = temp[j-1];
                    }
                    ans = left+up;
                    temp[j]=ans;
                    left_past = ans;
                }
                
            }
            dp = temp;
        }
        return ans;
        
    }
};