class Solution {

bool bfs_color(vector<vector<int>>& graph,int ele,int col,vector<int> &color){

    color[ele]=col;


    for(auto p:graph[ele]){
        if(color[p]== -1){
            if(bfs_color(graph,p,!col,color)==false){
                return false;
            }
        }else if(color[p] == col){
            return false;
        
        }
    }
    
    return true;

}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V=graph.size();
    
        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i]== -1){
                if(!bfs_color(graph,i,0,color)){
                    return false;
                }
            }
        }
        return true;
    }
};