class Solution {
int conver_char_to_int(char s){
    if(s == 'M'){
        return 1000;
    }
    if(s == 'V'){
        return 5;
    }
     if(s == 'X'){
        return 10;
    }
     if(s == 'L'){
        return 50;
    }
     if(s == 'C'){
        return 100;
    }
     if(s == 'D'){
        return 500;
    }
    return 1;
}
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = conver_char_to_int(s[n-1]);
        int prev = sum;
        int curr;

        for(int i=n-2;i>=0;i--){
            int curr = conver_char_to_int(s[i]);
            if(curr >= prev){
                sum += curr;
            }else{
                sum -= curr;
            }
            prev = curr;
        }
        return sum;
    }
};