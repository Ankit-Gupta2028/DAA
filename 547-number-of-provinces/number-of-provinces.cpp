class Solution {
private:
    void dfs(int node,vector<int> &visited,vector<int> v1[]){
        visited[node]=1;
        for(auto x: v1[node]){
            if(visited[x]==0){
                dfs(x,visited,v1);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> edges[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && isConnected[i][j]==1){
                    edges[i].push_back(j);
                }
                
            }
        }
        vector<int> visited(V,0);
       int ans=0;

        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                ans+=1;
                dfs(i,visited,edges);
                
            }
        }
        return ans;
    }
};