class Solution {
bool bfs_color(vector<vector<int>>& graph,int i,vector<int> &color,int newcolor){

    color[i]=newcolor;

    for(auto ele: graph[i]){
        if(color[ele]== -1 ){
            if(bfs_color(graph,ele,color,!newcolor)== false){
                return false;
            }
        }else{
            if(color[ele] == newcolor){
                return false;
            }
        }
        
    }


    return true;

}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        // vector<int> adj[V];
        // for(int i=0;i<graph.size();i++){
        //     adj[graph[i][0]].push_back(graph[i][1]);
        //     adj[graph[i][1]].push_back(graph[i][0]);
        // }
        vector<int> visited(V,0);
        vector<int> color(V,-1);
        int newcolor=0;

        for(int i=0;i<V;i++){
            if(color[i]== -1){
                if(!bfs_color(graph,i,color,newcolor)){
                    return false;
                }
            }
        }
        return true;
    }
};