class Solution {
private:
    vector<int> NSE(vector<int> &heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> s1;
       

        for(int i=n-1;i>=0;i--){
            int ele=heights[i];
            while(!s1.empty() && heights[s1.top()]>=ele){
                s1.pop();
            }
            if(s1.empty()){
                ans[i]=n;
            }else{
                ans[i]=s1.top();
            }
            s1.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int> &heights){
        vector<int> ans;
        stack<int> s1;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int ele=heights[i];
            while(!s1.empty() && heights[s1.top()]>=ele){
                s1.pop();
            }
            if(s1.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s1.top());
            }
            s1.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse=PSE(heights);
        vector<int> nse=NSE(heights);
        int n=heights.size();

        int LRA=0;

        for(int i=0;i<n;i++){
            int num=heights[i];
            int left=i-pse[i];
            int right=(nse[i]-i)-1;
            int area=num*(left+right);
            LRA=max(LRA,area);
        }
        return LRA;
    }
};