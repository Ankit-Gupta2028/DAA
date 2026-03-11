class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s1;
        int check_k=0;
        int n= num.size();

        for(int i=0;i<n;i++){
            char curr=num[i];
            while(!s1.empty() && (curr-'0') < (s1.top()-'0') && check_k<k ){
                s1.pop();
                check_k+=1;
            }
            s1.push(curr);
        } 
        
        while(check_k<k && !s1.empty()){
            s1.pop();
            check_k+=1;
        }
        if(s1.size()==0){
            return "0";
        }

        string ans;
        int n1=s1.size();
        for(int i=0;i<n1;i++){
            ans+=s1.top();
            s1.pop();
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0){
            return "0";
        }

        reverse(ans.begin(),ans.end());
        return ans;     
 
    }
};