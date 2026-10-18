class Solution {
int pascalTriangleI(int r, int c) {
        
        r= r-1;
        c = c-1;
        int pt = 1;

        for(int i=0;i<c;i++){
            pt = pt * (r - i);
            pt = pt/(i+1);
        }
        return pt;

    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        

        for(int i=0;i<numRows;i++){
            vector<int> curr;
            for(int j=0;j<=i;j++){
                int curr_ele = pascalTriangleI(i+1,j+1);
                curr.push_back(curr_ele);
            }
            ans.push_back(curr);
        }
        return ans;
       
    }
};