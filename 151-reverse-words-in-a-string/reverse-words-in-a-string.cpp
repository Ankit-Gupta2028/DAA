class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
       int last_change = n;
       string ans;

       for(int i=n-1;i>=0;i--){
            if(s[i] == ' '){
                if(last_change > i+1){
                    if(!ans.empty()){
                        ans+=" ";
                    }
                
                    ans += s.substr(i+1,last_change-i-1);
                }
               
                last_change = i;
            }
            
       }
       if(last_change > 0){
            if(!ans.empty()){
                ans+=" ";
            }
            ans += s.substr(0,last_change);
     
       }
         return ans;
    }
};