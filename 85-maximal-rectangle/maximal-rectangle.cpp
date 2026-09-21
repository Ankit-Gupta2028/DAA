class Solution {
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s1;
        int left=0,right=0;
        int LRH=0;


        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(!s1.empty() && curr <= heights[s1.top()]){

                int index_pop_ele=s1.top();
                s1.pop();
                right=i;

                if(s1.empty()){
                    left= -1;
                }else{
                    left= s1.top();
                }

                LRH=max(LRH,(heights[index_pop_ele]*(right-left-1)));
              
            }
            s1.push(i);
        }
        while(!s1.empty()){

            int index_pop_ele=s1.top();
            s1.pop();
            right=n;

            if(s1.empty()){
                left=-1;
            }else{
                left=s1.top();
            }

            LRH=max(LRH,(heights[index_pop_ele]*(right-left-1)));
        }
        return LRH;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> curr_size(m,0);
        int ans ;
        ans = INT_MIN;
      

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    curr_size[j] +=1 ;
                }else{
                    curr_size[j] = 0 ; 
                }
            }
            ans = max(ans,largestRectangleArea(curr_size)) ;
        }
        return ans;

    }
};