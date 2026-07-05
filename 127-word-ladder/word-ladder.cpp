class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s1(wordList.begin(),wordList.end());
        if(s1.find(endWord) == s1.end()) return 0;
        s1.erase(beginWord);

        queue<pair<string,int>> q1;
        q1.push({beginWord,1});

        while(!q1.empty()){
            auto ele= q1.front();
            q1.pop();
            string word= ele.first;
            int transformation = ele.second;

            for(int i=0;i<word.size();i++){
                for(char j='a';j<='z';j++){
                    string word2=word;
                    word2[i]=j;
                    if(s1.find(word2)!= s1.end()){
                        if(word2 == endWord){
                            return transformation+1;
                        }
                        q1.push({word2,transformation+1});
                        s1.erase(word2);
                    }
                }
            }

        }
        return 0;
    }
};