class Solution {
public:
    int numberOfSubstrings(string s) {
        int store[3]={-1,-1,-1};
        int Num_of_Substrings=0;
        for(int i=0;i<s.size();i++){

            store[s[i]-'a']=i;
             Num_of_Substrings+= 1 + min({store[0],store[1],store[2]});
            // if(store[0]!=-1 && store[1]!=-1 && store[2]!=-1 ){
            //     Num_of_Substrings+= 1 + min({store[0],store[1],store[2]});
            // }
        }
        return Num_of_Substrings;
    }
};