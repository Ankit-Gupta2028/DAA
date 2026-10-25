class Solution {
vector<int> nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;

        while(i >= 0 ){
            if(nums[i] < nums[i+1] ){
                break;
            }
            i--;
        }
        if(i < 0){
            reverse(nums.begin(),nums.end());
        }else{
            int greater_than_i = INT_MAX;
            int index;
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i] && greater_than_i > nums[j]){
                greater_than_i = nums[j];
                index = j;
                }
            }
        swap(nums[index],nums[i]);
        sort(nums.begin()+ i+1,nums.end());
        }
        return nums;

        
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n =nums.size();
        int fact = 1;
        for(int i = 1;i<=n;i++){
            fact *= i;
        }
        vector<vector<int>> ans;
        ans.push_back(nums);
        for(int i=1;i<fact;i++){
            nums = nextPermutation(nums);
            ans.push_back(nums);
        }
        return ans;
        
    }
};