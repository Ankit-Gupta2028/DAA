class Solution {
bool isvaild(int row,int col,int n,int m){
    if(row <0 || row >= n || col== -1 || col>=m){
        return false;
    }
    return true;
}
void bfs(vector<vector<int>> &image,vector<vector<int>> &vis,int sr, int sc,int color,int newColor){

    queue<pair<int,int>> q1;
    q1.push({sr,sc});
    vis[sr][sc]=1;
    image[sr][sc]=newColor;

    int n = image.size();
    int m = image[0].size();

    int drow[]={-1,0,0,1};
    int dcol[]={0,-1,1,0};

    while(!q1.empty()){

        auto ele=q1.front();
        q1.pop();
        int row=ele.first;
        int col=ele.second;

        for(int i=0;i<4;i++){
            if(isvaild(row+drow[i],col+dcol[i],n,m)){
                if(image[row+drow[i]][col+dcol[i]]==color && vis[row+drow[i]][col+dcol[i]]==0){

                    q1.push({row+drow[i],col+dcol[i]});
                    vis[row+drow[i]][col+dcol[i]]=1;
                    image[row+drow[i]][col+dcol[i]]=newColor;

                }
            }
        }  
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int oldcolor=image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        bfs(image,vis,sr,sc,oldcolor,color);
        return image;
    }
};