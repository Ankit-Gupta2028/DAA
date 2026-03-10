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
                v[i]= -1;
            }
            s1.push(i);
        }
        return v;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9 +7;
        int n=arr.size();
        vector<int> pse=PSE(arr);
        vector<int> nse=NSE(arr);
        int sum=0;

        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq=(1LL*left*right)%mod;
            long long curr_sum=(freq*arr[i])%mod;
            sum=(sum+curr_sum)%mod;
        }
        return sum;
        
    }
};