class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int n = s.size();
        char prev_char = s[0];
        int count =1;
        int lCS = 1;
        for(int i=1;i<n;i++){
            if((s[i] - 'a') - 1 == (prev_char- 'a')){
                prev_char = s[i];
                count +=1;
            }else{
               lCS = max(count,lCS) ;
               prev_char = s[i];
               count = 1;
            }
        }
        lCS = max(count,lCS) ;
        return lCS;
    }
};