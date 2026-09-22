class Solution {
bool check (char s){
    if ((s >= 'a' && s <= 'z') ||
            (s >= 'A' && s <= 'Z') ||
            (s >= '0' && s <= '9')) {
            return true;
        }
        return false;
}
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        
            while(i < j ){
                char left = tolower(s[i]);
                char right = tolower(s[j]);

                if(!check(left)){
                    i++;
                }else if(!check(right)){
                    j--;

                }else{
                    if(left != right){
                        return false;
                    }
                    i++;
                    j--;
                }
              
            }
            return true;
    }
};