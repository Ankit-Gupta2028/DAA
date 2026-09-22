class Solution {
public:
    bool rotateString(string s, string goal) {
           if(s.size() != goal.size()){
                return false;
            }

            string double_s = s+s;
            if(double_s.find(goal) == string::npos) {
                return false;
            }
            return true;
    }
};