class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> s1;
    
        for(int i=n-1;i>=0;i--){
            int curr=temperatures[i];
            while(!s1.empty() && curr>=temperatures[s1.top()]){
                s1.pop();
            }
            if(s1.empty()){
                ans[i]=0;
            }else{
                ans[i]=s1.top()-i;
            }
            s1.push(i);
        }
        return ans;
    }
};