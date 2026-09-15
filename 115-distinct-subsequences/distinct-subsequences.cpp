class Solution {
        int modeule = 1e9 + 7;

public:
    int numDistinct(string s, string t) {
         int index1 = s.size();
       int index2 = t.size();

       vector<int> curr (index2+1,0);
        vector<int> prev (index2+1,0);

        
        curr[0] = 1; 
        prev[0] = 1;
       
        for(int i=1;i<=index1;i++){
            for(int j = 1;j<=index2;j++){

                if(s[i-1] == t[j-1]){

                    curr[j] = (prev[j-1] + prev[j]) % modeule;

                }else{

                    curr[j] = prev[j];

                }
            }
            prev = curr;
        }
        return curr[index2];

    }
};