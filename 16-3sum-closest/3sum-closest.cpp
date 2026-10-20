class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans ;
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j < k){
                int total = nums[i]+nums[j]+nums[k];

                if(total == target){
                    return total;
                   
                }else if(total > target){
                    if(abs(total - target) < diff){
                        diff = abs(total - target);
                        ans = total;
                    }
                    k--;
                }else{
                    if(abs(total - target) < diff){
                        diff = abs(total - target);
                        ans = total;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};