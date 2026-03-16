class Solution {
public:
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
};