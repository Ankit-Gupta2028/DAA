class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s1;
        int n=asteroids.size();
        

        for(int i=0;i<n;i++){
            int curr=asteroids[i];
            
            while(!s1.empty() && curr < 0 && s1.top() > 0){
                if(abs(curr) > abs(s1.top())){
                    s1.pop();
                }else if(abs(curr) == abs(s1.top()) ){
                    s1.pop();
                    curr=0;
                    break;
                }else{
                    curr=0;
                    break;
                }
            }

            if(curr!=0){
                s1.push(curr);
            }
        }
        vector<int> ans(s1.size());
        for(int i=s1.size()-1;i>=0;i--){
          
            ans[i]=s1.top();
            s1.pop();
        }
        return ans;
    }
};