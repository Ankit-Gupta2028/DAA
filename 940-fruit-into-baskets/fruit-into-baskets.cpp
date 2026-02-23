class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> m1;
        int right=0,left=0;
        int max_len=0;

        while(right<n){
          m1[fruits[right]]++;
          if(m1.size()>2){
            m1[fruits[left]]--;
            if(m1[fruits[left]]==0){
              m1.erase(fruits[left]);
            }
            left++;
          }
          if(m1.size()<=2){
            max_len=max(max_len,(right-left)+1);
          }
          right+=1;
        }
        return max_len;
    }
};