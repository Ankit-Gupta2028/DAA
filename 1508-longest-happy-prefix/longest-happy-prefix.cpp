class Solution {
public:
    string longestPrefix(string s) {
         int n = s.size();
        vector<int> kmp(n,0);

        int j = 0;
        for(int i=1;i<n;i++){
            while(j> 0 && s[i] != s[j]){
                j = kmp[j-1];
            }

            if(s[i] == s[j]){
                kmp[i] = j+1;
                j++;
            }
            
        }
        int total = kmp[n-1];
        if(total == 0){
            return "";
        }
        return s.substr(0,total);
    }
};