class Twitter {
public:
    int Time=0;
    unordered_map<int,vector<pair<int,int>>> Tweet;
    unordered_map<int, unordered_set<int>> following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
         Tweet[userId].push_back({Time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
            
    vector<int> news;
    priority_queue<pair<int,int>> p1;
    following[userId].insert(userId);
    for(auto &it: following[userId]){
        for(auto &x: Tweet[it]){
            p1.push({x.first,x.second});

        }
    }
    while(!p1.empty()){
        auto top1=p1.top();
        p1.pop();
        news.push_back(top1.second);
        if(news.size()==10){
            break;
        }
    }
    return news;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */