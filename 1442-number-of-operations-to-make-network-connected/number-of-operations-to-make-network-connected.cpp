class DisjointSet {
    
public:
    vector<int> rank,parent,Size;
    
        int find_parent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find_parent(parent[u]);
    }
    DisjointSet(int n) {

        parent.resize(n+1,0);
        rank.resize(n+1,0);
        Size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return {-1};
        }

        DisjointSet dv(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(dv.find_parent(u) != dv.find_parent(v)){
                dv.unionBySize(u,v);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int Parent = dv.find_parent(i);
            if(Parent == i){
                ans+=1;
            }
        }
        return ans-1;
    }
};