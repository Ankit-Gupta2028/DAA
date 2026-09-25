class Solution {
pair<int,int> max_string(string &s,int start, int end){
    while(start >=0 &&  end < s.size() && s[start]==s[end]){
        start--;
        end++;
    }
    return {start+1,end-1};
}
public:
    string longestPalindrome(string s) {
        int n  = s.size();
       if(n== 0 ){
        return "";
       }
        int max_len = 0;
        int start_index = 0;

        for(int i=0;i<n;i++){
            auto odd = max_string(s,i,i);
            auto even = max_string(s,i,i+1);

            if((odd.second - odd.first)+1 > max_len){
                max_len = (odd.second - odd.first)+1;
                start_index = odd.first;
            }
            if((even.second - even.first)+1 > max_len){
                max_len = (even.second - even.first)+1;
                start_index = even.first;
            }

            
        }
        return s.substr(start_index,max_len);
    }
};