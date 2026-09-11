class Solution {

public:
    int longestCommonSubsequence(string text1, string text2) {
        
      int s1 = text1.size();
        int s2 = text2.size();

        vector<int> prev(s2+1,0);
        vector<int> curr(s2+1,0);

        for(int index1=1;index1<=s1;index1++){
            for(int index2=1;index2<=s2;index2++){
                int Equal = 0;
                int Not_Equal = 0;
                if(text1[index1-1] == text2[index2-1]){
                    Equal = 1+ prev[index2-1];
                }else{
                    int first = curr[index2-1];
                    int second = prev[index2];
                    Not_Equal = max(first,second);
                }
                curr[index2] = max(Equal,Not_Equal);
            }
             prev = curr;

        }
        return prev[s2];
        
    }
};