class Solution {
public:
    int minInsertions(string s) {
       
        int n = s.size();
        int open = 0;
        int ans = 0;
        int i=0;
        
        while(i<n){

            if(s[i] == '('){
                open ++;

            }else{

                if(i+1 < n && s[i+1] == ')' ){
                    i++;
                }else{
                    ans++;
                }

                if(open > 0){
                    open -=1;
                }else{
                    ans +=1;
                }
            }
            i++;
        }

        return ans + (2*open);
    }
};