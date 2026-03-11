class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s1;
        int check_k=0;
        int n= num.size();

        for(int i=0;i<n;i++){
            char curr=num[i];
            while(!s1.empty() && (curr) < (s1.top()) && check_k<k ){
                s1.pop();
                check_k+=1;
            }
            s1.push(curr);
        } 
        
        while(check_k<k && !s1.empty()){
            s1.pop();
            check_k+=1;
        }


        string ans="";
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