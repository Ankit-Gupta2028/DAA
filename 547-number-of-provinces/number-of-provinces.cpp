class Solution {
private:

    void dfs(vector<int> adj[],vector<int> &vis,int node){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(adj,vis,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
       vector<int> Adj[n];

       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                    if(isConnected[i][j]==1 && i!=j){
                        Adj[i].push_back(j);
                        Adj[j].push_back(i);
                    }
                

            }
       }
       int ans=0;
       vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(Adj,vis,i);
            }
        }
        return ans;
    }
};