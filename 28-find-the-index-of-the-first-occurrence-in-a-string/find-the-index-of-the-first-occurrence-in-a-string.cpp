class Solution {
int  search(string pat, string txt) {

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

      
       
        for(int i=0;i<=m - n;i++){
             if( hash_text == hash_pat){
                if(txt.substr(i,n) == pat){
                    return i ;
                    break;
                }
                
            }

            hash_text = (hash_text - (((txt[i] - 'a' )+1) * prime_left)% mod + mod) % mod ;
            
           hash_text =  (hash_text +(((txt[i + n] - 'a')+1)*cur_prime) % mod) % mod;
            hash_pat = (hash_pat * prime) % mod;

            cur_prime = (cur_prime * prime) % mod;
            prime_left = (prime_left * prime) % mod;

            

        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        
        return search(needle,haystack);
    }
};