class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        if(sum == 0 || sum > 9*num){
            return "";
        }
        int nines = sum/9;
        int remain = sum%9;
        string ans (nines,'9');

        
        if(remain > 0){
            ans.push_back(remain + '0');
        }
        ans.append(num - ans.size(), '0');
        return ans;
    }
};