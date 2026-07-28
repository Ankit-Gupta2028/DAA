class Solution {
private:
    // DelRow and delCol for neighbors
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    /* Helper Function to check if a 
    pixel is within boundaries */
    bool isValid(int &i, int &j, 
                 int &n, int &m) {
        
        // Return false if pixel is invalid
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        
        // Return true if pixel is valid
        return true;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

       priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> q1;

        q1.push({grid[0][0],{0,0}});

        vector<vector<int>> min_time(n,vector<int>(m,INT_MAX));
        min_time[0][0]=grid[0][0];

        while(!q1.empty()){
            auto ele = q1.top();
            int time = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            q1.pop();

            if(row == n-1 && col==m-1){
                return time;
            }
            if (time > min_time[row][col])
                continue;

            for(int i=0;i<4;i++){
                int newrow = row+delRow[i];
                int newcol = col+delCol[i];
                
                if(isValid(newrow,newcol,n,m)){

                    int max_time = max(time,grid[newrow][newcol]);

                    if(min_time[newrow][newcol]>max_time){
                        min_time[newrow][newcol]=max_time;
                        q1.push({max_time,{newrow,newcol}});
                    }
                }
            }


        }
        return min_time[n-1][m-1];
        
    }
};