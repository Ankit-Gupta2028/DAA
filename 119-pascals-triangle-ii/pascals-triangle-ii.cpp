class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long pt = 1;
        ans.push_back(pt);

        for(int i=1;i<=rowIndex;i++){
            pt = pt*(rowIndex+1-i);
            pt = pt/(i);
            ans.push_back(pt);

        }
        return ans;
    }
};