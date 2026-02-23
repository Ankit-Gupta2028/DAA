class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        queue<int> q1;
        int left=0;
        int right=0;
        int max_cons=0;

        while(right < n){
            if(nums[right] == 0){
                q1.push(right);
                if(k==0){
                    int first_zero=q1.front();
                    q1.pop();
                    left=first_zero+1;
                }else{
                    k-=1;
                }
                
            }
            max_cons=max(max_cons,(right-left)+1);
            right=right+1;
        }
        return max_cons;
    }
};