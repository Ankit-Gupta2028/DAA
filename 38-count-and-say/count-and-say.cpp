class Solution {
public:
    string countAndSay(int n) {
        
        string curr = "";
        string prev = "1";
        
        int count;
        char prev_char;

        for(int i=1;i<n;i++){
            curr = "";

            count = 1;
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
        }


        return prev;
    }
};