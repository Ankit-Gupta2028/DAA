class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         int n=arr.size();
       unordered_map<int,int> m1;
       priority_queue<int,vector<int>,greater<int>> p1;

       for(int i=0;i<n;i++){
            if(m1.find(arr[i])==m1.end()){
                p1.push(arr[i]);
            }
            m1[arr[i]]=1;
       }
        int rank=1;
       while(!p1.empty()){
            m1[p1.top()]=rank;
            rank++;
            p1.pop();
       }
       vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(m1[arr[i]]);
        }
        return ans;
    }
};