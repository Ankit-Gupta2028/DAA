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
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify_down(nums,i,n);
        }
        int check=0;
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            check+=1;
            if(check==k){
                return nums[0];
                break;
            }
            
            nums[i]=nums[0];
            nums[0]=curr;
            heapify_down(nums,0,i);
        }
        return -1;
        
    }
};