class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int i=1;
        int n = nums.size();
        char curr;
        int count= 0;
        while(i<n){
            if(nums[i] - nums[i-1] > 0){
                curr = '+';
                count +=1;
                break;
            }else if(nums[i] - nums[i-1] < 0){
                curr = '-';
                count+=1;
                break;
            }
            i++;
        }
        for(int k = i+1;k<n;k++){
            if((nums[k] - nums[k-1] > 0) && curr == '-'){
                count +=1;
                curr = '+';
            }else  if((nums[k] - nums[k-1] < 0) && curr == '+'){
                 count +=1;
                curr = '-';
            }
        }
        return count+1;
    }
};