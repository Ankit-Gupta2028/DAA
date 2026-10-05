class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();

        int prev_char = s[0];
        int count = 1;
        int max_1 = 0;
        int max_0 = 0;

        for(int i=1;i<n;i++){
            if(s[i] == prev_char){
                count +=1;
            }else{
                if(prev_char == '1'){
                    max_1 = max(max_1,count);
                }else{
                    max_0 = max(max_0,count);
                }
                prev_char = s[i];
                count = 1;
            }
        }
        if(prev_char == '1'){
            max_1 = max(max_1,count);
        }else{
            max_0 = max(max_0,count);
        }
        if(max_1 > max_0){
            return true;
        }
        return false;
    }
};