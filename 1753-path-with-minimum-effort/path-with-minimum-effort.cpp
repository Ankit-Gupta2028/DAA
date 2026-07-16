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
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>> > q1;

        int n= heights.size();
        int m= heights[0].size();
        vector<vector<int>> max_effort(n,vector<int>(m,1e9));

        q1.push({0,{0,0}});
        max_effort[0][0]=0;
        int delrow[]={-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q1.empty()){
            auto ele = q1.top();
            int effort = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            q1.pop();

            for(int i=0;i<4;i++){
                int newrow= delrow[i]+row;
                int newcol = delcol[i]+col;

                if(isvaild(heights,newrow,newcol)){
                    int new_effort = abs(heights[row][col] - heights[newrow][newcol]);
                    int maximum_effort= max(effort,new_effort);
                   

                    if( maximum_effort < max_effort[newrow][newcol]){
                        q1.push({maximum_effort,{newrow,newcol}});
                        max_effort[newrow][newcol]=maximum_effort;

                    }
                    
                }
            }

            
        }
        return max_effort[n-1][m-1];

    }
};