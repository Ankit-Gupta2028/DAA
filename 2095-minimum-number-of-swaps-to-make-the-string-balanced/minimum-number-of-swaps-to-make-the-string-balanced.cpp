class Solution {
public:
    int minSwaps(string s) {
       int open  = 0;
        
        int n = s.size();
        

        

        for(int i=0;i<n;i++){
            if(s[i] == '['){
                open +=1;
            }
            if(s[i] == ']'){
                
                if(open > 0){
                    open -=1;
                    
                }
            }
        }
        

       return (open+1)/2 ;
       
    }
};