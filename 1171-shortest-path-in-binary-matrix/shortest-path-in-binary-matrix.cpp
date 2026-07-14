class Solution {
bool isvaild(vector<vector<int>> &grid,int row ,int col){
    int n=grid.size();
    int m=grid[0].size();
    if(row <0 || row>=n){
        return false;
    }
    if(col < 0 || col >=m){
        return false;
    }
    return true;
}
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> source;
        pair<int, int> destination;
        source.first = 0;
        source.second = 0;
        destination.first = n-1;
        destination.second = m-1;

        if(source == destination){
            if(grid[0][0]==0){
                return 1;
            }
            
        }
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }

        int delrow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delcol[] = {-1,  0,  1,-1, 1,-1, 0, 1};
       
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[source.first][source.second]== 1;

        queue<pair<int,pair<int,int>>> q1;
        q1.push({1,{source.first,source.second}});

        while(!q1.empty()){
            auto ele = q1.front();
            int dis = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            q1.pop();

            for(int i=0;i<8;i++){
                int newrow = delrow[i]+row;
                int newcol = delcol[i]+col;

                if(isvaild(grid,newrow,newcol)){
                    if(grid[newrow][newcol]==0){
                        if(newrow == destination.first && newcol==destination.second){
                            return dis+1;
                        }else{
                            if(visited[newrow][newcol]== 0){
                                q1.push({dis+1,{newrow,newcol}});
                                visited[newrow][newcol]= 1;
                            }
                            
                        }
                    }
                }


            }

        }
        return -1;

    }
};