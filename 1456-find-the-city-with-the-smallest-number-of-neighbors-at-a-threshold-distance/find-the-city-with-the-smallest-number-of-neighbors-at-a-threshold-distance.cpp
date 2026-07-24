class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>> matrix(n,vector<int>(n,1e9));

            for(auto it: edges){
                matrix[it[0]][it[1]]=it[2];
                matrix[it[1]][it[0]]=it[2];
            }


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){

                    if(j==k){
                        matrix[j][k]=0;
                    }

                    if(matrix[j][i] == 1e9 || matrix[i][k] == 1e9 ){
                        continue;
                    }

                    if(matrix[j][k] == 1e9 ){
                         matrix[j][k]=matrix[j][i] + matrix[i][k];
                    }else if(matrix[j][i] + matrix[i][k] <  matrix[j][k]){
                        matrix[j][k]=matrix[j][i] + matrix[i][k];
                    }

                }
            }
        }
        int min_cites1=INT_MAX;
        int final_answer = -1;

         for(int i=0;i<n;i++){
            int min_cites2 = 0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j] <=distanceThreshold ){
                    min_cites2+=1;
                }
            }
            if(min_cites1 > min_cites2){
                min_cites1 = min_cites2;
                final_answer = i;
            }else if(min_cites1 == min_cites2){
                final_answer=i;

            }

         }
         return final_answer;
    }
};