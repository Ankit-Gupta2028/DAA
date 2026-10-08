class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {

         unordered_map<int,int> m1;
         int n = nums.size();
         int count = 0;
         int ans = -1;

        for(int i=0;i<n;i++){
            if(nums[i] % 2 ==0){
                m1[nums[i]] +=1;

                if(m1[nums[i]] > count){
                    count = m1[nums[i]];
                    ans = nums[i];
                }else if(m1[nums[i]] == count){
                    if( ans > nums[i]){
                        ans = nums[i];
                    }
                }
            }
        }
        return ans ;
    }
};