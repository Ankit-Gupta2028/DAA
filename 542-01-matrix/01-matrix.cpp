class Solution {
private:
    bool isvaild(int i,int j,int n,int m){
    if(i<0 || i>=n){
        return false;
    }
    if(j<0 || j>=m){
        return false;
    }
    return true;
    
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
          int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        queue<pair<int,pair<int,int>>> q1;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q1.push({0,{i,j}});
                    vis[i][j]=1;
                }    
            }
        }

        while(!q1.empty()){
            auto ele=q1.front();
            q1.pop();
            int dis=ele.first;
            int row=ele.second.first;
            int col = ele.second.second;
            ans[row][col]=dis;

            for(int i=0;i<4;i++){
                int newrow=row+drow[i];
                int newcol=col+dcol[i];

                if(isvaild(newrow,newcol,n,m)){
                    if(vis[newrow][newcol]==0 ){
                        q1.push({dis+1,{newrow,newcol}});
                        vis[newrow][newcol]=1;
                    }
                }
            }
        
        
        }
        return ans;
    }
};