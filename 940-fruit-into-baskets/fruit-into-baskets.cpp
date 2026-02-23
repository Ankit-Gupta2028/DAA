class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),max_num_fruits=0;
        int basket1=fruits[0], basket2 = -1;
        int last_fruit=fruits[0], last_fruit_index=0;
        int left=0,right=0;
        

        while(right<n){
          if((fruits[right]!= basket1) && basket2== -1){
            basket2=fruits[right];
            last_fruit=fruits[right];
            last_fruit_index=right;
          }else if((fruits[right]!= basket1) && (fruits[right]!= basket2) ){

              basket1=last_fruit;
              basket2=fruits[right];
              left=last_fruit_index;
              last_fruit=fruits[right];
              last_fruit_index=right;

          }else {

            if(fruits[right]!=last_fruit){
              last_fruit=fruits[right];
              last_fruit_index=right;
            }

          }
          max_num_fruits=max(max_num_fruits,(right-left)+1);
          right=right+1;
        
        }
        return max_num_fruits;
    }
};