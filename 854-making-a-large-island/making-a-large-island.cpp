
class DisjointSet {

public:
    
    vector<int> rank,parent,Size;
    DisjointSet(int n) {

        parent.resize(n+1,0);
        rank.resize(n+1,0);
        Size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

    }
    int find_parent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find_parent(parent[u]);
    }

    bool find(int u, int v) {
        if(find_parent(u) == find_parent(v)){
            return true;
        }
        return false;
    }

    void unionBySize(int u, int v) {
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if(parent_u == parent_v)
            return;

         if(Size[parent_u] >= Size[parent_v]){
            parent[parent_v]=parent_u;
            Size[parent_u]+=Size[parent_v];

        }else{
              parent[parent_u]=parent_v;
              Size[parent_v]+=Size[parent_u];
        }
       
    }
};
class Solution {
private:
   bool isValid(int &i, int &j, int &n) {
        
        // Return false if pixel is invalid
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= n) return false;
        
        // Return true if pixel is valid
        return true;
    }   

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int Size = n*m;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        DisjointSet dv(Size);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1 ){
                  
                    int row = i;
                    int col = j;
                    int index = n*row + col;
  
                    for(int k=0;k<4;k++){
                        int newrow = delRow[k]+row;
                        int newcol = delCol[k]+col;
                        int newindex = newrow*n + newcol;

                        if(isValid(newrow,newcol,n)  && grid[newrow][newcol]==1){   
                                dv.unionBySize(index,newindex);
                                
                        }

                    }    
                }
            }
        }
        
        int island = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){

                        set<int> s1;
                        for(int k=0;k<4;k++){
                            
                            int newrow = delRow[k]+i;
                            int newcol = delCol[k]+j;

                           

                            if(isValid(newrow,newcol,n)  && grid[newrow][newcol]==1){

                                int index = n*newrow + newcol;
                                int Parent = dv.find_parent(index);
                                s1.insert(Parent);
                            }

                        }
                        int ans = 1;
                        for(auto it : s1){
                            ans+= dv.Size[it];
                        }
                        island = max(ans,island);
                }
            }
        }
        for(int i=0;i<n*n; i++){
            island = max(island , dv.Size[dv.find_parent(i)]);
        }
        return island;
    }
};