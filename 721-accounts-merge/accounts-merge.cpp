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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string,int> email_parent;
        int N = accounts.size();

        DisjointSet dv(N);

        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(email_parent.find(accounts[i][j]) == email_parent.end()){
                    email_parent[accounts[i][j]]=i;
                }else{
                    dv.unionBySize(i,email_parent[accounts[i][j]]);
                }
            }
        }

        vector<string> parent_of_mail[N];
        for(auto it : email_parent){
            int Parent = dv.find_parent(it.second);
            parent_of_mail[Parent].push_back(it.first);
        }

        vector<vector<string>> ans;
        for(int i=0;i<N;i++){

            if(parent_of_mail[i].empty()){
                continue;
            }

            sort(parent_of_mail[i].begin(),parent_of_mail[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto it:parent_of_mail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);

        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};