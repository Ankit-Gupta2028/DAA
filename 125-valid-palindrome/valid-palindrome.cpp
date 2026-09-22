class Solution {
public:
    bool isPalindrome(string s) {
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            result += s[i];
        }
    }
    for (int i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
        int n = result.size();
            int i = 0;
            int j = n-1;
            while(i < j ){
                if(result[i] != result[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
    }
};