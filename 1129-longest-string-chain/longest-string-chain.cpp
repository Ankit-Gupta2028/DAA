class Solution {
    bool LSC(string &a,string &b){

        if(a.size() != b.size()-1){
            return false;
        }
        
        int i=0;
        int j=0;
        while(i != a.size() && j!= b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i == a.size()){
            return true;
        }
        return false;
    }
    static bool compare( string& a,  string& b){
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
         int n = words.size();
            sort(words.begin(),words.end(),compare);
           vector<int> dp(n,1);
           int ans = 1;

           for(int i=0;i<n;i++){
            int index = i-1;
            while(index >= 0){
                if(LSC(words[index],words[i])){
                    dp[i]= max(dp[i],dp[index]+1);
                }
                index --;
            }
            ans = max(ans,dp[i]);
           }
           return ans;
    }
};