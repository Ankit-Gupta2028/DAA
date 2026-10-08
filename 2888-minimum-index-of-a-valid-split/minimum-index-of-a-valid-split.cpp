class Solution {
public:
    int minimumIndex(vector<int>& nums) {

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

        count = 0;
        int i = 0;

        while( i < n){
            if(nums[i] == ans){
                count +=1;
            }
            if(count > (i+1)/2){
                break;
            }
            i++;
        }
    

        int j = i+1;
        count = 0;
        while(j < n){
            if(nums[j] == ans){
                count +=1;
            }
            j++;
        }
       
        
        if((n-i-1)/2 < count ){
            return i;
        }
        return -1;
    }
};