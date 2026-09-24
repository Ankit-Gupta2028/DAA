class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;

        while(s[i] == ' ' && i<n){
            i++;
        }
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        long long  ans = 0;
        while(i<n && isdigit(s[i])){
           
                ans = (ans*10) + (s[i] - '0');
            

            if(ans * sign >= INT_MAX){
                return INT_MAX;
            }
            if(ans * sign <= INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return ans*sign;
    }
};