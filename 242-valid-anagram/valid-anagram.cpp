class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.size() != t.size()){
                return false;
            }
            
			int m1[256] = {0};
            int m2[256] = {0};

            for(int i=0;i<s.size();i++){
                m1[s[i]] += 1;
                m2[t[i]] += 1;
            }

            for(int i=0;i<s.size();i++){
                if(m1[s[i]] != m2[s[i]]){
                    return false;
                }
            }
            return true;

    }
};