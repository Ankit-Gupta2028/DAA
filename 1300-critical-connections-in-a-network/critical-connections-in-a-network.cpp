class Solution {
void dfs(int node,int parent,int &count,vector<int> adj[],vector<int> &vis,vector<int> &tin, vector<int> &low,vector<vector<int>> &bridges){

    vis[node]=1;
    for(auto it : adj[node]){

        if(it == parent){
            continue;
        }
        if(vis[it]==0){
            tin[it]=count+1;
            low[it]=count+1;
            count+=1;
            dfs(it,node,count,adj,vis,tin,low,bridges);
            

            low[node]=min(low[node],low[it]);

            if(tin[node] < low[it]){
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(it);
                bridges.push_back(temp);
            }
        }else{
            low[node]=min(low[node],low[it]);
        }
    }

}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];

        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        int count=0;
        tin[0]=0;
        low[0]=0;

        dfs(0,-1,count,adj,vis,tin,low,bridges);
        return bridges;
    }
};