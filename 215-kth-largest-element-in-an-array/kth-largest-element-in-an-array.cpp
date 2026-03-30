class Solution {


            
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k>nums.size()){
            return -1;
        }
       int n=nums.size();
      
        int left=0;
        int right=n-1;
         while (left <= right) {

            int pivot_index = left + rand() % (right - left + 1);
            int pivot = nums[pivot_index];

            // 3-way partition
            int i = left, lt = left, gt = right;

            while(i<=gt){
                if(pivot < nums[i]){
                    swap(nums[lt],nums[i]);
                    i++; lt++;
                }else if(pivot > nums[i]){
                    swap(nums[gt],nums[i]);
                    gt--;
                }else{
                    i++;
                }
            }
            if(k-1 < lt){
                right=lt-1;
            }else if(k-1 > gt){
                left=gt+1;
            }else{
                return pivot;
            }
         }
         return -1;
    }
    
};