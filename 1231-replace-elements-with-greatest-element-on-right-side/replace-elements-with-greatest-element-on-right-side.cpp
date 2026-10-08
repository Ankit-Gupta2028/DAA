class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n,-1);
        int Maxi = arr[n-1];

        for(int i=n-2;i>=0;i--){
            ans[i] = Maxi;
            Maxi = max( Maxi,arr[i]);
        }
        return ans;
    }
};