class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> min_cost(n,1e9);
        min_cost[src]=0;
        

        
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
           
        }
          queue<pair<int,pair<int,int>>> q1;

          q1.push({0,{k,src}});
          while(!q1.empty()){
            auto ele = q1.front();
            int cost = ele.first;
            int stop = ele.second.first;
            int node = ele.second.second;
            q1.pop();

            for(auto it: adj[node] ){
                int curr_cost = it.second;
                int curr_node = it.first;


                if(stop >= 0 ){
                    if(curr_node == dst && curr_cost+cost < min_cost[curr_node]){
                        min_cost[curr_node] = curr_cost+cost;

                    }
                }
                if(stop>0){
                    if(curr_cost+cost < min_cost[curr_node]){
                    min_cost[curr_node] = curr_cost+cost;
                    q1.push({curr_cost+cost,{stop-1,curr_node}});

                }

                }
                
            }
          }
          if(min_cost[dst]== 1e9){
            return -1;
          }
          return min_cost[dst];
    }
};