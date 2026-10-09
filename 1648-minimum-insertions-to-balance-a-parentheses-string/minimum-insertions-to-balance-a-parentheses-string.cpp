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
                if(i+1 < n){
                    if(s[i+1] == ')' && open > 0){
                        i+=1;
                        open -=1;
                       
                    }else if(s[i+1] == ')' && open  == 0){
                        ans +=1;
                        i+=1;
                    }else if(s[i+1] != ')' && open > 0){
                        ans +=1;
                        open -=1;
                    }else if(s[i+1] != ')' && open  == 0){
                        ans +=2;
                    }
                }else{
                    if(open > 0){
                        ans +=1;
                        open -=1;
                    }else{
                        ans +=2;
                    }
                }
            }
            i++;
        }


        
        
       
      

        return ans + (2*open);
    }
};