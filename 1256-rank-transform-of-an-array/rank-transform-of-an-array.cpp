class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         int n=arr.size();
       unordered_map<int,int> m1;
       vector<int> sorted_array=arr;
       sort(sorted_array.begin(),sorted_array.end());
       sorted_array.erase(unique(sorted_array.begin(),sorted_array.end()),sorted_array.end());

       for(int i=0;i<sorted_array.size();i++){
             m1[sorted_array[i]]=i+1;
       }
       vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(m1[arr[i]]);
        }
        return ans;
    }
};