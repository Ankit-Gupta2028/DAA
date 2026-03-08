class Solution {
private:
    bool matched(char open,char close){
        if((open=='(' && close==')')|| 
        (open=='[' && close==']')||
        (open=='{' && close=='}')){
            return true;
        }
        return false;
    }
public:
    bool isValid(string s) {
        
        stack<char> s1;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                s1.push(s[i]);
            }else{
                if(s1.empty()){
                    return false;
                }
                if((matched(s1.top(),s[i]))==false){
                    return false;
                }else{
                    s1.pop();
                }
            

            }
        }
        return s1.empty();

    }
};