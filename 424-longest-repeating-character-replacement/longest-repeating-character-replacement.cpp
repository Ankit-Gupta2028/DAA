class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0;
       int n=s.size(),change=0;
       int max_freq=0,max_len=0;
       int m1[26]={0};
       

       while(right<n){
            
            m1[s[right]-'A']++;
            
            
            max_freq=max(max_freq,m1[s[right]-'A']);
            change=((right-left)+1)-max_freq;
            if(change>k){
                m1[s[left]-'A']--;
                left+=1;
            }
            if(change<=k){
                max_len=max(max_len,(right-left)+1);
            }
            
            right+=1;
            

       }
       return max_len;
    }
};