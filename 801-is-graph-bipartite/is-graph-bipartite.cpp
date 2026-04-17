class Solution {

bool bfs_color(vector<vector<int>> &adj,int i,vector<int> &color){
    queue<int> q1;
    q1.push(i);
    color[i]=0;

    while(!q1.empty()){
        int ele=q1.front();
        q1.pop();

        for(auto p:adj[ele]){
            if(color[p]== -1){
                if(color[ele]==0){
                    color[p]=1;
                }else{
                    color[p]=0;
                }
                q1.push(p);
            }else{
                if(color[p] == color[ele]){
                    return false;
                }
            }
        }
    }
    return true;

}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
  

 
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]== -1){
                if(!bfs_color(graph,i,color)){
                    return false;
                }
            }
        }
        return true; 
    }
};