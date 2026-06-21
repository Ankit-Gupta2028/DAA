class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto ele: adj[i]){
                indegree[ele]+=1;
            }
        }
        
        queue<int> q1;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q1.push(i);
            }
            
        }
        vector<int> ans;

        while(!q1.empty()){
            int num=q1.front();
            q1.pop();
            ans.push_back(num);

            for(auto ele: adj[num]){
                indegree[ele]-=1;
                if(indegree[ele]==0){
                    q1.push(ele);
                }

            }
        }
        if(ans.size() != numCourses){
            return {};
        }
        return ans;
    }
};