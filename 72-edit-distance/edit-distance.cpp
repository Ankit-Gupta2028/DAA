class Solution {
private:
    int Edit_distance(int index1,int index2,string &start, string &target,  vector<vector<int>> &dp){
        if(index1 < 0){
            return index2+1;
        }
        if(index2 < 0){
            return index1+1;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(start[index1] == target[index2]){
            dp[index1][index2]= Edit_distance(index1-1,index2-1,start,target,dp);
        }else{
             dp[index1][index2] =  1 + 
             min(Edit_distance(index1-1,index2,start,target,dp),
             min(Edit_distance(index1-1,index2-1,start,target,dp),
             Edit_distance(index1,index2-1,start,target,dp)));
        }
        return dp[index1][index2];
        
    }
public:
    int minDistance(string word1, string word2) {
        
        int index1 = word1.size();
        int index2 = word2.size();

        vector<vector<int>> dp(index1,vector<int>(index2,-1));

        return Edit_distance(index1-1,index2-1,word1,word2,dp);
    }
};