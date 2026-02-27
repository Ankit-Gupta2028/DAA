class Solution {
private:
    int Number_Of_Odd_Subarrays(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }
        int left=0,right=0;
        int sum=0,count=0;
        
        while(right<nums.size() ){

            sum+=(nums[right]%2);
            while(sum>k){
                sum-=(nums[left]%2);
                left+=1;
            }
            count+=(right-left)+1;
            right+=1;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums.size()==0){
            return 0;
        }
        return Number_Of_Odd_Subarrays(nums,k) - Number_Of_Odd_Subarrays(nums,k-1);
    }
};