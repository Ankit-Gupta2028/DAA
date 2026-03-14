class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left_index=0,right_index=height.size()-1;
        int left_max=0,right_max=0;
        int ans=0;
        while(left_index < right_index){
            if(height[left_index] <= height[right_index]){
                if(left_max>height[left_index]){
                    ans+=left_max-height[left_index];
                }else{
                    left_max=max(left_max,height[left_index]);
                }
                left_index+=1;
                
            }else{
                if(right_max>height[right_index]){
                    ans+=right_max-height[right_index];
                }else{
                    right_max=max(right_max,height[right_index]);
                }
                right_index-=1;
            }
        }
        return ans;
    }
};