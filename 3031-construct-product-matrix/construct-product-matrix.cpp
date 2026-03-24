class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        if(grid.size()==0){
            return {};
        }

        int n=grid.size();
        int m=grid[0].size();
        vector<int> store(n*m);

        int idx=0;
        int mod=12345;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                store[idx]=grid[i][j];
                idx++;
            }
        }

        vector<long long > prefix(n*m,1);
        vector<long long > postfix(n*m,1);
        for(int i=1;i<n*m;i++){
            prefix[i]=(prefix[i-1]*store[i-1])%mod;
        }
        for(int i=n*m-2;i>=0;i--){
            postfix[i]=(postfix[i+1]*store[i+1])%mod;
        }
        vector<vector<int>> ans(n,vector<int>(m));
        idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(prefix[idx]*postfix[idx]) %mod;
                idx++;
            }
        }
        return ans;

        
    }
};