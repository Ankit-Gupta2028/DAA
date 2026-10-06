class Solution {
void swap1(int start,int end,vector<int>& nums){
    while(start < end){
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k%n;
        swap1(0,n-1,nums);
        swap1(0,k-1,nums);
        swap1(k,n-1,nums);
    }
};