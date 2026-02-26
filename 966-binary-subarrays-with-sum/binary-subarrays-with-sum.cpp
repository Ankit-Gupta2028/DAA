class Solution {
private:
    int NumSubarraysWithSum(vector<int>& nums, int goal){
        int left=0,right=0;
        int sum=0,count=0;
        
        while(right<nums.size() && left<=right){
            if(goal<0){
                return 0;
            }
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left+=1;
            }
            count+=(right-left)+1;
            right+=1;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(nums.size()==0){
            return 0;
        }
        return NumSubarraysWithSum(nums,goal)-NumSubarraysWithSum(nums,goal-1);
    }
};