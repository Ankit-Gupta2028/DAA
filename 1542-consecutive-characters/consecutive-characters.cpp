class Solution {
public:
    int maxPower(string s) {
        
        int n = s.size();
        char prev_char = s[0];
        int count = 1;
        int MaxPower = 1;

        for(int i=1; i<n; i++){
            if(s[i] == prev_char  ){
                count +=1;
                
            }else{
                MaxPower = max(count,MaxPower);
                prev_char = s[i];
                count = 1;
            }
        }
        MaxPower = max(count,MaxPower);
        return MaxPower;

    }
};