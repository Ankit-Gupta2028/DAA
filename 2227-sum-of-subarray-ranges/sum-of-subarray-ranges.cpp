class Solution {
private:
    vector<int> NSE(vector<int> &arr){
        int n=arr.size();
        vector<int> v(n);
        stack<int> s1;

        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(!s1.empty() && curr <= arr[s1.top()]){
                s1.pop();
            }
            if(!s1.empty()){
                v[i]=s1.top();
            }else{
                v[i]=n;
            }
            s1.push(i);
        }
        return v;
    }
    vector<int> PSE(vector<int> &arr){
        int n=arr.size();
        vector<int> v(n);
        stack<int> s1;

        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(!s1.empty() && curr < arr[s1.top()]){
                s1.pop();
            }
            if(!s1.empty()){
                v[i]=s1.top();
            }else{
                v[i]=-1;
            }
            s1.push(i);
        }
        return v;
    }
    vector<int> NLE(vector<int> &arr){
        int n=arr.size();
        vector<int> v(n);
        stack<int> s1;

        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(!s1.empty() && curr >= arr[s1.top()]){
                s1.pop();
            }
            if(!s1.empty()){
                v[i]=s1.top();
            }else{
                v[i]=n;
            }
            s1.push(i);
        }
        return v;
    }
    vector<int> PLE(vector<int> &arr){
        int n=arr.size();
        vector<int> v(n);
        stack<int> s1;

        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(!s1.empty() && curr > arr[s1.top()]){
                s1.pop();
            }
            if(!s1.empty()){
                v[i]=s1.top();
            }else{
                v[i]=-1;
            }
            s1.push(i);
        }
        return v;
    }
    long long Sum_subarray_min_ele(vector<int> &nums){
     
        int n=nums.size();

        vector<int> pse=PSE(nums);
        vector<int> nse=NSE(nums);

        long long sum=0;

        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq=(1LL*left*right);
            long long curr_sum=(1LL*freq*nums[i]);
            sum=sum+curr_sum;
        }
        return sum;

    }
    long long Sum_subarray_max_ele(vector<int> &nums){
        
        int n=nums.size();
        vector<int> ple=PLE(nums);
        vector<int> nle=NLE(nums);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-ple[i];
            int right=nle[i]-i;
            long long freq=(1LL*left*right);
            long long curr_sum=(1LL*freq*nums[i]);
            sum=sum+curr_sum;
        }
        return sum;

    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return Sum_subarray_max_ele(nums)-Sum_subarray_min_ele(nums);
    }
};