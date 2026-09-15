class Solution {

public:
    int minDistance(string word1, string word2) {
        
        int index1 = word1.size();
        int index2 = word2.size();

      


        vector<int> curr(index2+1,0);
        vector<int> prev(index2+1,0);

        for(int i=0;i<=index2;i++){
       
            prev[i] = i;
        }
        
        for(int i=1;i<=index1;i++){
            curr[0] = i;
            for(int j=1;j<=index2;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j]= prev[j-1];
                }else{
                curr[j]=   1 + 
                min(prev[j],min(prev[j-1],
                curr[j-1]));
                }
            }
            prev = curr;
        }
        return prev[index2];
         
         
    }
};