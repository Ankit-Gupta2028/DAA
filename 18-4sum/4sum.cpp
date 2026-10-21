class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){

            if(i> 0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j=i+1;j<n;j++){

                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                int k = j+1;
                int l = n-1;
                
                while(k < l){

                    long long total = ( long long) nums[i]+ ( long long) nums[j]+ ( long long) nums[k]+ ( long long) nums[l];

                    if(total > target){

                        l--;
                    }else if(total < target){

                        k++;

                    }else{

                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                        while(k < l && nums[l] == nums[l+1]){
                            l--;
                        }

                    }
                }
            }
        }
        return ans;
    }
};