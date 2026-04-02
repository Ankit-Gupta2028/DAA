class Twitter {
public:
    unordered_set<int> s1[1000];
    vector<pair<int,int>> Tweet;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        Tweet.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
            
    vector<int> news;
    int Tweet_size=Tweet.size();
    for(int i=Tweet_size -1;i>=0 && news.size()<10 ;i--){
        if(Tweet[i].first==userId){
            news.push_back(Tweet[i].second);
        }
        else if(s1[userId].find(Tweet[i].first)!=s1[userId].end()){
            news.push_back(Tweet[i].second);
        }
    }
    return news;
    }
    
    void follow(int followerId, int followeeId) {
        s1[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        s1[followerId].erase(followeeId);
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