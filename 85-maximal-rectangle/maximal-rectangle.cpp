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
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> histro(n,vector<int>(m));
        
        for(int i=0;i<m;i++){

            int curr=matrix[0][i]-'0';
            histro[0][i]=curr;

            for(int j=1;j<n;j++){

                if((matrix[j][i]-'0')==1){
                    curr+=1;
                    histro[j][i]=curr;
                }else{
                    curr=0;
                    histro[j][i]=curr;
                }
            }

        }

        int max_rectangle=0;
        for(int i=0;i<n;i++){
            int curr_max=largest_histro_rec(histro[i]);
            max_rectangle=max(max_rectangle,curr_max);
        }
        return max_rectangle;
    }
};