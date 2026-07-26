class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }


         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
         q1.push({0,k});


         vector<int> min_weight(n+1 , INT_MAX);
         min_weight[0]=-1;
         min_weight[k]=0;

         while(!q1.empty()){
            auto ele = q1.top();
            int weight = ele.first;
            int node = ele.second;
            q1.pop();

            for(auto it : adj[node]){
                int neweight = weight+it.second;
                int newnode = it.first;

                if(neweight < min_weight[newnode]){
                    min_weight[newnode] = neweight;
                    q1.push({neweight,newnode});
                }

            }

         }
         int ans=0;
         for(int i=0;i<=n;i++){
            if(min_weight[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,min_weight[i]);
         }
         return ans;
    }
};