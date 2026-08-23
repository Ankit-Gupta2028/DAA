class Solution {
int max_money(vector<int>& money, int n, vector<int> &dp){

    if(n == 0 ){
        return money[0];
    } if(n < 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }
    
        int pick = money[n] + max_money(money,n-2,dp);

        int non_pick = 0 + max_money(money,n-1,dp);
        
        
    
    dp[n] = max(non_pick,pick);
    return max(non_pick,pick);
     
    
}
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n ==1 )
            return nums[0];
        

        vector<int> dp(n,-1);
        vector<int> dp2(n,-1);
        vector<int> temp1;
        vector<int> temp2;

      

        for(int i=0;i<n;i++){
            if(i != 0){
                temp1.push_back(nums[i]);
            }
            if( i != n-1){
                 temp2.push_back(nums[i]);
            }
            
        }

        int ans1 = max_money(temp1,n-2,dp);
        int ans2 = max_money(temp2,n-2,dp2);

        return max(ans1,ans2);
    }
};