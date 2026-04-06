class Solution {
private:
    void bfs( vector<int> adj[],vector<int> &vis,int node){
        queue<int> q1;
        q1.push(node);
        vis[node]=1;

        while(!q1.empty()){

            int curr=q1.front();
            q1.pop();
           

            for(auto it:adj[curr]){
                if(vis[it]==0){
                    vis[it]=1;
                    q1.push(it);
                }
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
                    }
                

            }
       }
       int ans=0;
       vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                bfs(Adj,vis,i);
            }
        }
        return ans;
    }
};