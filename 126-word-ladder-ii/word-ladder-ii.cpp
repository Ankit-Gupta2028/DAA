class Solution {
void dfs(unordered_map<string,int> &m1,string new_word,int new_word_len,vector<string> &temp,string beginWord,vector<vector<string>> &ans){
    
    if(new_word == beginWord){
        reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        reverse(temp.begin(),temp.end());
        return;
    }
    for(int i=0;i<new_word.size();i++){
        for(char j='a';j<='z';j+=1){
            string temp_word=new_word;
            temp_word[i]=j;
            if(m1.find(temp_word) != m1.end()){
                if(m1[temp_word] == new_word_len-1){
                    temp.push_back(temp_word);
                    dfs(m1,temp_word,m1[temp_word],temp,beginWord,ans);
                    temp.pop_back();
                }
            }
        }
    }



}
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    
    unordered_set<string> s1(wordList.begin(),wordList.end());
        unordered_map<string,int> m1;
        vector<vector<string>> ans;
        
        if(s1.find(endWord) == s1.end()) return ans;

        queue<pair<string,int>> q1;
        q1.push({beginWord,0});
        s1.erase(beginWord);
        m1[beginWord]=0;
        bool check = false;

        while(!q1.empty()){
            
            auto ele= q1.front();
            q1.pop();
            string word = ele.first;
            int transformation = ele.second;

            for(int i=0;i<word.size();i++){
                for(char j='a';j<='z';j++){
                    string word2 = word;
                    word2[i]=j;
                    if(s1.find(word2)!= s1.end()){
                       
                        q1.push({word2,transformation+1});
                        m1[word2]=transformation+1;
                        s1.erase(word2);
                    }
                }
               
            }
           

        }
        vector<string> temp;
        temp.push_back(endWord);
        dfs(m1,endWord,m1[endWord],temp,beginWord,ans);
        return ans;

    }
};