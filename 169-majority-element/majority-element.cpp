class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n = nums.size();

        int count = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(count == 0){
                count = 1;
                ans = nums[i];

            }else if(ans != nums[i]){
                count -=1;
            }else{
                count +=1;
            }
        }
        return ans;
        
    }
};