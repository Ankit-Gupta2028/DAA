class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ;
        int open = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                open +=1;
                if(open > 1){
                    ans+= '(';
                }
                
                
            }else if(s[i] == ')'){
                open -=1;
                if(open != 0){
                    
                    ans+=')';
                }
               
            }
        }
        return ans;
    }
};