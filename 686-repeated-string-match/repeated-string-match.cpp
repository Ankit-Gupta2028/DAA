class Solution {
bool search(string pat, string txt) {

            int n  = pat.size();
            int m = txt.size();
            
            int mod = 101;
            int prime = 7;
        
            int hash_text = 0;
            int hash_pat = 0;

            int cur_prime = 1;
            int prime_left = 1;

        for(int i=0;i<n;i++){

            hash_text += (((txt[i] - 'a')+1)*cur_prime) % mod;
            hash_pat += (((pat[i] - 'a')+1)*cur_prime) % mod;

            cur_prime = (cur_prime * prime) % mod;
        }

        vector <int> ans;
       
        for(int i=0;i<=m - n;i++){
             if( hash_text == hash_pat){
                if(txt.substr(i,n) == pat){
                    return true;
                    break;
                }
                
            }

            hash_text = (hash_text - (((txt[i] - 'a' )+1) * prime_left)% mod + mod) % mod ;
            
           hash_text =  (hash_text +(((txt[i + n] - 'a')+1)*cur_prime) % mod) % mod;
            hash_pat = (hash_pat * prime) % mod;

            cur_prime = (cur_prime * prime) % mod;
            prime_left = (prime_left * prime) % mod;

            

        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        string ans = "";
        int count = 0;

        while(ans.size() < b.size()){
            ans += a;
            count +=1;
        }
        if(search(b,ans)){
            return count;
        }
        ans += a;
        count +=1;
        if(search(b,ans)){
            return count;
        }
        return -1;
    }
};