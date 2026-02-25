class Solution {
public:
    string minWindow(string s, string t) {
        
        int freq_t[255]={0};
        int min_len=INT_MAX;
        int string_index=-1;
        int cnt=0;
        int left=0,right=0;
        for(char i:t){
            freq_t[i-'A']+=1;
        }
        while(right<s.size()){
            if(freq_t[s[right]-'A']>0){
                cnt+=1;
            }
            freq_t[s[right]-'A']--;
            while(cnt>=t.size()){
                if(((right-left)+1)<min_len){
                    min_len=(right-left)+1;
                    string_index=left;
                }
                
                

                freq_t[s[left]-'A']+=1;
                if(freq_t[s[left]-'A']>0){
                    cnt-=1;
                }
                left+=1;
            }

            right+=1;
        }
        if(string_index==-1){
            return "";
        }
        return s.substr(string_index,min_len);
    }
};