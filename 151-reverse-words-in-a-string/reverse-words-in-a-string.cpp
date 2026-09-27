class Solution {
void reverse_string(int start,int end,string &s){
    while(start <= end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
public:
    string reverseWords(string s) {
        int n = s.size();
       
       reverse_string(0,n-1,s);
       
       int i=0;
       int j=0; 
       int start = 0;
       int end = 0;

        while(j < n){
            while(j<n && s[j]== ' '){
                j++;
            }
            if( j==n){
                break;
            }
            start = i;

            while(j<n && s[j]!= ' ' ){
                s[i] = s[j];
                i++;
                j++;
            }
            end = i - 1;
            reverse_string(start,end,s);

            if(j < n){
                s[i] = ' ';
                i++;
            }
        }
        if(i>0 && s[i-1] == ' '){
            i--;
        }
        return s.substr(0,i);
    }
};