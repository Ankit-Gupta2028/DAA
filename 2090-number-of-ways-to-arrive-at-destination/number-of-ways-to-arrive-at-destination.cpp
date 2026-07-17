class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

    vector<pair<int,int>> adj[n];
      for(int i=0;i<roads.size();i++){
        adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
      }

      vector<long long> min_dist(n,LLONG_MAX);
      min_dist[0]=0;

       priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int> >> q1;
       q1.push({0,0});

       vector<int> ways(n,0);
       ways[0]=1;
       int mod = 1e9+7;
       
       

       while(!q1.empty()){
            auto ele = q1.top();     
           long long node = ele.second;
            long long time = ele.first;
            q1.pop();

           
            for(auto it : adj[node])  {
                long long new_node = it.first;
                long long new_time = it.second;

                if(new_time+time < min_dist[new_node]){
                    min_dist[new_node]=new_time+time;
                    q1.push({new_time+time,new_node});
                    ways[new_node]=ways[node];
                }else if(new_time+time == min_dist[new_node]){
                     ways[new_node]= (ways[new_node]+ways[node])% mod;
                }
            }
            

        }
        return ways[n-1] % mod;
      
    }
};