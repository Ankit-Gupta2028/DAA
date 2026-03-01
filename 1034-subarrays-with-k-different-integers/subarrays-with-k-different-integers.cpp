class Solution {
    private:
    int Sub_arrays_With_KDistinct(vector<int>& nums, int k){
        if(k==0){
            return 0;
        }
        int count=0;
   
        int left=0,right=0;
        unordered_map<int,int> m1;

        while(right<nums.size()){

            m1[nums[right]]+=1;

            while(m1.size()>k){
                m1[nums[left]]-=1;
                if(m1[nums[left]]==0){
                    m1.erase(nums[left]);
                }
                left+=1;
            }
            count+=(right-left)+1;
            right+=1;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(nums.size()==0){
            return 0;
        }
        return Sub_arrays_With_KDistinct(nums,k)-Sub_arrays_With_KDistinct(nums,k-1);
    }
};