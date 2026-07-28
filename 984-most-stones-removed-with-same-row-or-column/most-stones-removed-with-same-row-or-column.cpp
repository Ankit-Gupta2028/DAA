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

        if(parent_u == parent_v){
            return ;
        }

         if(Size[parent_u] >= Size[parent_v]){
            parent[parent_v]=parent_u;
            Size[parent_u]+=Size[parent_v];

        }else{
              parent[parent_u]=parent_v;
              Size[parent_v]+=Size[parent_u];
        }
       
    }
};

class disjoint{
public:

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
         int Row = 0;
        int Col = 0;
        

        for(auto it : stones){
            Row = max(Row,it[0]);
            Col = max(Col,it[1]);
        }

        DisjointSet dv(Row+Col+1);

        unordered_map<int,int> mpp_stones;

        for(auto it: stones){

            int row = it[0];
            int col = Row+it[1]+1;

            dv.unionBySize(row,col);

            mpp_stones[row]=1;
            mpp_stones[col]=1;
            
        }
        int ans =0;
        for(auto it: mpp_stones){
            if(it.first == dv.find_parent(it.first)){
                ans ++;
            }
        }
        return n-ans;
    }
};