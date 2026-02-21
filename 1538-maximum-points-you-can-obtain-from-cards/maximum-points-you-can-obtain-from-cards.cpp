class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();

      int left=0;
      int right=k-1;
      int max_pts=0;

      for(int i=0;i<k;i++){
        max_pts+=cardPoints[i];
      }

      if(n==k){
        return max_pts;
      }

      int sum=max_pts;
      for(int i=0;i<k;i++){

        sum-=cardPoints[right];

        if(left==0){
          left=n-1;
        }else{
          left=left-1;
        }
        

        if(right==0){
          right=n-1;
        }else{
          right=right-1;
        }
        

        sum+=cardPoints[left];
        max_pts=max(max_pts,sum);

      }
      return max_pts;
      
    }
};