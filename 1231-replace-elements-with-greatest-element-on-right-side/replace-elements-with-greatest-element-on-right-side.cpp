class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int n = arr.size();
        
        int Maxi = arr[n-1];
        arr[n-1] = -1;
        

        for(int i=n-2;i>=0;i--){
            int curr = arr[i];
            arr[i] = Maxi;
            Maxi = max( Maxi,curr);
        }
        return arr;
    }
};