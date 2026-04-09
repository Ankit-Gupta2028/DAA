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
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q1;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q1.push({0,{i,j}});
                    visited[i][j]=1;
                }
                
            }
        }

        while(!q1.empty()){
            auto ele=q1.front();
            auto dis=ele.first;
            auto row=ele.second.first;
            auto col=ele.second.second;
            q1.pop();

            ans[row][col]=dis;

            for(int i=0;i<4;i++){
                    int newrow = row+drow[i];
                    int newcol = col+dcol[i];
                    if(isvaild(newrow,newcol,n,m) && visited[newrow][newcol]==0){
                        q1.push({dis+1,{newrow,newcol}});
                        visited[newrow][newcol]=1;
                    }
            }


        }



        return ans;
    }
};