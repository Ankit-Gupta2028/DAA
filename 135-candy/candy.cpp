class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
        int total_candy=1;
        int i=1;
      
        while(i<n){

            if(ratings[i]==ratings[i-1]){
                total_candy+=1;
                i++;
                continue;
            }
            int high=1;
            while(i<n && ratings[i]>ratings[i-1]){
                high+=1;
                total_candy+=high;
                i++;

            }
             int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
            
                total_candy+=down;
                down+=1;
                i++;
            }

            if(high<down){
                total_candy+=(down-high);
            }
        }

        
        return total_candy;
    }
};