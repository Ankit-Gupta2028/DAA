class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0){
            return 0;
        }
        vector<int> max_right(n);
        int right_max=height[n-1];
        for(int i=n-1;i>=0;i--){
            right_max=max(right_max,height[i]);
            max_right[i]=right_max;
        }

        int ans=0;
        int left_max=height[0];
        for(int i=0;i<n;i++){
            left_max=max(left_max,height[i]);
            if((left_max > height[i]) && max_right[i]>height[i]){
                ans+=min(left_max,max_right[i])-height[i];
            }
        }
        return ans;
        
    }
};