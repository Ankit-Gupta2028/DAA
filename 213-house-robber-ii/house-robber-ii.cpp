class Solution {
int nonAdjacent(vector<int>& nums) {

        int n = nums.size();

        int prev2 = 0;
        int prev = nums[0];

        for(int i=1;i<n;i++){

            int pick = nums[i];

            if(i>1){
                pick += prev2;
            }
            int not_pick = 0 + prev;

            prev2 = prev;
            prev = max(pick,not_pick);

            
        }


        return prev;

    }
public:
    int rob(vector<int>& nums) {
       
        int n = nums.size();

        if(n ==1 )
            return nums[0];
        
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

        int ans1 = nonAdjacent(temp1);
        int ans2 = nonAdjacent(temp2);

        return max(ans1,ans2);
    }
};