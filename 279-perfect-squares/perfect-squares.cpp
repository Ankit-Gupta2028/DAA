class Solution {

public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            int x = sqrt(i);
            if(x*x == i){
                nums.push_back(i);
            }
        }

        int N = nums.size();
        vector<int> dp(n+1,0);

        for(int i=0;i<=n;i++){
            if(i % nums[0] == 0){
                dp[i]= i / nums[0];
            }else{
                dp[i]=1e9;
            }
        }

        for(int index = 1;index<N;index++){
                vector<int> temp(n+1,0);
            for(int target = 0;target<=n;target++){
                int not_take = dp[target];

                 int take = 1e9;
                 if(target >= nums[index]){
                    take = 1+ temp[target - nums[index]];
                }

                temp[target] = min(take ,not_take);
            }
            dp = temp;
        }
        return dp[n];

        

    }
};