class Solution {

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V=graph.size();
        vector<int> indegree(V,0);
        vector<int> safe;
        vector<int> Rev_adj[V];
        queue<int> q1;
        

        for(int i=0;i<V;i++){
            for(auto ele: graph[i]){
                Rev_adj[ele].push_back(i);
            }
        }
        

        for(int i=0;i<V;i++){
            for(auto ele: Rev_adj[i]){
                indegree[ele]+=1;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q1.push(i);
            }
        }
        while(!q1.empty()){
            int num=q1.front();
            safe.push_back(num);
            q1.pop();

            for(auto ele : Rev_adj[num]){
                indegree[ele]-=1;
                if(indegree[ele]==0){
                    q1.push(ele);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
        
    }
};