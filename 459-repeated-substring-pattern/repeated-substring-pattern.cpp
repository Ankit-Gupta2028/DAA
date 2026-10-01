class Solution {
vector <int> KMP(string s){

    int n = s.size();
    int i = 1;
    int j = 0;
    vector <int> Lps(n,0);

    for(int i=1;i<n;i++){

        if(s[i] == s[j]){
            Lps[i] = j + 1;
            j++;
        }else{
            while(j >0 && s[i] != s[j]){
             
                j = Lps[j-1];

            }
            if(s[i] == s[j]){
                    Lps[i] = j + 1;
                    j++;
                   
            }

        }

    }
    return Lps;
}
public:
    bool repeatedSubstringPattern(string s) {

        vector<int> Lps = KMP(s);
        int n = s.size();

        int num = n - Lps[n-1];

        if(Lps[n-1] > 0 && n % num == 0){
            return true;
        }
        return false;
        
    }
};