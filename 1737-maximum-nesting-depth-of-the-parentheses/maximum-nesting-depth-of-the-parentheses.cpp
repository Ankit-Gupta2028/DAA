class Solution {
public:
    int maxDepth(string s) {
        int check = 0;

        int n = s.size();
        int max_depth = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                check +=1;
                max_depth = max(max_depth,check);
            }else if(s[i] == ')'){
                check -=1;
            }
        }
        return max_depth;
    }
};