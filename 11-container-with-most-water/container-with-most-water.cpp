class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans = 0;

        while( i < j){
            int curr = (min(height[i],height[j])) * (j-i);

            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
            ans = max(curr,ans);
        }
        return ans ;
    }
};