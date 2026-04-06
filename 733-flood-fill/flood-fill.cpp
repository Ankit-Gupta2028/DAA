class Solution {
 bool isvaild(int i,int j,int n,int m){
    if(i<0 || i>=n){
        return false;
    }
    if(j<0 || j>=m){
        return false;
    }
    return true;
}
void bfs(vector<vector<int>> &image,vector<vector<int>> &vis,int i,int j,int newColor,int curr_colour,vector<vector<int>> &image_demo){
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q1;
        vis[i][j]=1;
        q1.push({i,j});
        image_demo[i][j]=newColor;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q1.empty()){
            auto ele=q1.front();
            q1.pop();
            int row=ele.first;
            int col=ele.second;

            for(int i=0;i<4;i++){
              int newrow=row+drow[i];
              int newcol=col+dcol[i];

                if(isvaild(newrow,newcol,n,m)){
                    if(image[newrow][newcol]  == curr_colour && vis[newrow][newcol]==0){
                            vis[newrow][newcol]=1;
                            image_demo[newrow][newcol]=newColor;
                            q1.push({newrow,newcol});
                    }
                }

                
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int n=image.size();
            int m=image[0].size();
            int curr_colour=image[sr][sc];
           vector<vector<int>> vis(n,vector<int>(m,0)) ;
            vector<vector<int>> image_demo=image;

            bfs(image,vis,sr,sc,color,curr_colour,image_demo);
            return image_demo;
    }
};