class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.size() != t.size()){
                return false;
            }
            
			int m1[256] = {0};
            

            for(int i=0;i<s.size();i++){
                m1[s[i]] += 1;
              
            }
            for(int i=0;i<s.size();i++){
                m1[t[i]] -= 1;
              
            }

            for(int i=0;i<s.size();i++){
                if(m1[s[i]] != 0){
                    return false;
                }
            }
            return true;

    }
};