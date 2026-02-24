class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
       int right=0;
       int n=s.size();
       int max_freq=0;
       int max_len=0;
       unordered_map<int,int> m1;
       int change=0;

       while(right<n){
            
            m1[s[right]-'A']++;
            
            
            max_freq=max(max_freq,m1[s[right]-'A']);
            change=((right-left)+1)-max_freq;
            if(change>k){
                m1[s[left]-'A']--;
                if(m1[s[left]-'A']==0){
                    m1.erase(s[left]-'A');
                }
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