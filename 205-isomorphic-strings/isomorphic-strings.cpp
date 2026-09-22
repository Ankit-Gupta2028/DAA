class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> dp1(256,-1);
        vector<char> dp2(256,-1);

        for(int i=0;i<s.size();i++){
              if(dp1[s[i] ] != t[i] && dp1[s[i] ] != -1){
                    return false;
                }
                if(dp2[t[i] ] != s[i] && dp2[t[i] ] != -1){
                    return false;
                }

                dp1[s[i] ] = t[i];
                dp2[t[i] ] = s[i];


        }
        return true;
    }
};