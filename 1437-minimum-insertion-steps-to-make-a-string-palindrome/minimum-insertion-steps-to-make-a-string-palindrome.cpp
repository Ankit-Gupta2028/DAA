class Solution {
public:
    int minInsertions(string s) {
         string w = s;
            reverse(w.begin(),w.end());
            int n = s.size();
            vector<int> curr(n+1,0);
             vector<int> prev(n+1,0);

        
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(s[i-1] == w[j-1]){

                        curr[j]= 1+ prev[j-1];
                       

                    }else{

                        curr[j] = max(curr[j-1],prev[j]);
                      

                    }
                }
                prev = curr;
            }
            return n-curr[n];
    }
};