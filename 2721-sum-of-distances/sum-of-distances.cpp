class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,long long> count,sum;
        vector<long long> ans(n,0);

        for(int i=0;i<n;i++){

            int x = nums[i];
            ans[i] = count[x]*i - sum[x];

            count[x]+=1;
            sum[x]+=i;

            
        }
        count.clear();
        sum.clear();

        for(int i=n-1;i>=0;i--){

            int x = nums[i];
            ans[i] += sum[x] -  count[x]*i ;

            count[x]+=1;
            sum[x]+=i;

            
        }
        return ans;

    }
};