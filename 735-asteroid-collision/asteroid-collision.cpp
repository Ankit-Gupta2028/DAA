class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v1;
        int n=asteroids.size();
        

        for(int i=0;i<n;i++){
            int curr=asteroids[i];
            
            while(!v1.empty() && curr < 0 && v1.back() > 0){
                if(abs(curr) > abs(v1.back())){
                    v1.pop_back();
                }else if(abs(curr)== abs( v1.back()) ){
                    v1.pop_back();
                    curr=0;
                    break;
                }else{
                    curr=0;
                    break;
                }
            }

            if(curr!=0){
                v1.push_back(curr);
            }
        }
  
        return v1;
    }
};