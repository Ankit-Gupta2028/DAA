class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty = 0;

        for(int i=0;i<n;i++ ){
            vector<int> freq(26,0);

            for(int j=i;j<n;j++){
                freq[s[j] - 'a']+=1;

                int Max = INT_MIN;
                int Min = INT_MAX;

                for(int i=0;i<26;i++){
                    if(freq[i] > 0){
                        Max = max(Max,freq[i]);
                        Min = min(Min,freq[i]);
                    }
                }
                beauty += Max-Min;
            }
        }
        return beauty;
    }
};