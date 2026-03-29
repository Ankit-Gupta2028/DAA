class Solution {
private:
    void heapify_down(vector<int> &nums , int index,int n){
            
            while(true){
                int current=index;
                int left=2*index+1;
                int right=2*index+2;
                if(left<n && nums[left]>nums[current] ){
                    current=left;
                }
                if(right<n && nums[right]>nums[current] ){
                    current=right;
                }
                if(current == index){
                    break;
                }
                swap(nums[current],nums[index]);
                index=current;
    
            }

    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify_down(nums,i,n);
        }
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            nums[i]=nums[0];
            nums[0]=curr;
            heapify_down(nums,0,i);
        }
        return nums;
    }
};