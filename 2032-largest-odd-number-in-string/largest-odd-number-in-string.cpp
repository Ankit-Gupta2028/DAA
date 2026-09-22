class Solution {
public:
    string largestOddNumber(string num) {
        int i=0;
        int j = num.size()-1;

        while(j >= 0){
         
            int s = num[j] - '0';

            if(s % 2 == 0){
                j--;
                
            }else{
               
                break;
            }
        }
        while(i <= num.size()-1){
            if(num[i] == '0'){
                i++;
            }else{
                break;
            }
        }
        num.erase(j+1);
        num.erase(0,i);
        
        
        return num;
    }
};