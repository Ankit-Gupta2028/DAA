class Solution {
vector <int> KMP(string s){

    int n = s.size();
    int i = 1;
    int j = 0;
    vector <int> Lps(n,0);

    for(int i=1;i<n;i++){

        while(j>0 && s[i] != s[j]){
            j = Lps[j-1];
        }

        if(s[i] == s[j]){
            Lps[i] = j + 1;
            j++;
        }
      

    }
    return Lps;
}
public:
    string shortestPalindrome(string s) {
          
        int n = s.size();
        string duplicated = s;
        reverse(duplicated.begin(),duplicated.end());

        string z = s + '$' + duplicated;

        vector<int> lps = KMP(z);

        int equal_char = lps.back();

        string rem_char = s.substr(equal_char,n-equal_char);

        reverse(rem_char.begin(),rem_char.end());

        return rem_char + s;

    }
};