class Solution {
public:
    int minSwaps(string s) {
       int open  = 0;
        int close = 0;
        int n = s.size();
        

        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '['){
                open +=1;
            }
            if(s[i] == ']'){
                close+=1;
                if(open > 0){
                    open -=1;
                    close -=1;
                }
            }
        }
        

       ans = (open+1)/2 ;
       return ans;
    }
};