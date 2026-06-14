class Solution {
bool dfs(vector<vector<int>>& graph,vector<int> &visited,vector<int> &pathvis,int node,vector<int> &ans){
    pathvis[node]=1;
    visited[node]=1;

    for(auto ele:graph[node]){
        if(pathvis[ele]==1){
            return true;
        }else if(visited[ele]==0){
            if(dfs(graph,visited,pathvis,ele,ans)==true){
                return true;
            }
        }
       
    }
    ans[node]=1;
    pathvis[node]=0;
    return false;
        
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> visited(V,0);
        vector<int> path_visited(V,0);
        vector<int> safe(V,0);
       
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(graph,visited,path_visited,i,safe);
            }
            
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(safe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};