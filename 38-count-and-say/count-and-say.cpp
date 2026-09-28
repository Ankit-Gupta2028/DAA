class Solution {
public:
    string countAndSay(int n) {

        if(n == 1){
            return "1";
        }
        string prev = countAndSay(n-1);
        string curr = "";
        
        int count = 1;
        char prev_char;

        prev_char = prev[0];

        for(int i=1;i<prev.size();i++){
            if(prev[i] == prev_char){
                    count +=1;
            }else{
                curr += to_string(count);
                curr += prev_char;
                prev_char = prev[i];
                count = 1;
            }
        }
        curr += to_string(count);
        curr += prev_char;
        prev = curr;
        


        return prev;
    }
};