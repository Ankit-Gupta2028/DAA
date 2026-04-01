class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }

       unordered_map<int,int> arr;

        priority_queue<int> p1;
        
        for(int i:tasks){
            arr[i-'A']+=1;
        }
        for(auto &x: arr){
            p1.push(x.second);
        }

        
        int ans=0;
         

        while(!p1.empty()){
            vector<int> store;
            int cnt=0;
            for(int i=0;i<n+1;i++){
                if(!p1.empty()){
                    int freq=p1.top();
                    p1.pop();
                    freq--;
                    if(freq>0){
                        store.push_back(freq);
                       
                    }
                    cnt+=1;
                    

                }

            }
            for(int &i: store){
               
                p1.push(i);
                
                
            }
            if(p1.empty()){
                ans+=cnt;
            }else{
                ans+=n+1;
            }
  
        }
        return ans;
    }
};