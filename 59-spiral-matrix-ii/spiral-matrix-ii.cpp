class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int top = 0,bottom = n-1;
        int left = 0,right = n-1;
        vector<vector<int>> ans(n,vector<int>(n));
        int count = 1;

        while(top<=bottom && left<=right){

          for(int i=left;i<=right;i++){
            ans[top][i] = count;
            count+=1;
          }
          top++;
          for(int i=top;i<=bottom;i++){
            ans[i][right] = count;
            count+=1;
          }
          right--;
          if(top<=bottom){
             for(int i=right;i>=left;i--){
                ans[bottom][i] = count;
                count+=1;
            }
            bottom--;
          }
         
         if(left <= right){
            for(int i=bottom;i>=top;i--){
                ans[i][left]  = count;
                count+=1;
            }
            left++;
         }
        }
        return ans;


    }
};