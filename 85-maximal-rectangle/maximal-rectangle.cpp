class Solution {
private:
    int largest_histro_rec(vector<int> &arr){
        int n=arr.size();
        int left=0,right=0;
        stack<int> s1;
        int max_rect=0;
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(!s1.empty() && arr[s1.top()]>curr){
                int index=s1.top();
                s1.pop();
                int right=i;
                if(s1.empty()){
                    left=-1;
                }else{
                    left=s1.top();
                }
                max_rect=max(max_rect,arr[index]*(right-left-1));

            }
            s1.push(i);
        }
        while(!s1.empty()){
                int index=s1.top();
                s1.pop();
                int right=n;
                if(s1.empty()){
                    left=-1;
                }else{
                    left=s1.top();
                }
                max_rect=max(max_rect,arr[index]*(right-left-1));
        }
        return max_rect;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max_rectangular=0;
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int> histograms(m,0);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(matrix[i][j]-'0' == 1){
                    histograms[j]+=1;
                   
                }else{

                    histograms[j]=0;
                }
            }
            max_rectangular=max(max_rectangular,largest_histro_rec(histograms));
        }
       

        return max_rectangular;
    }
};