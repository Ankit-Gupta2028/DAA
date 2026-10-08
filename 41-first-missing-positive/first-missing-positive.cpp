class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i =0;

        while(i<n){
            if(nums[i] > 0 && nums[i] <= n){
                // correct index check // duplicate check
                if(nums[nums[i] - 1] != nums[i]){
                    
                    
                    swap(nums[i] , nums[nums[i] - 1] );
                    
                   
                }else{
                    i++;
                }
            }else{
                i++;
            }
            
        }
        int j = 0;
        while(j < n){
            if(nums[j] == j+1){
                j++;
            }else{
                return j+1;
            }
        }
        return n+1;
    }
};