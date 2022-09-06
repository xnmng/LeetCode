class Twitter {
    vector<int> history;
    unordered_map<int,int> mp1; // tweetId -> userId
    unordered_map<int,unordered_set<int>> mp2; // userId -> followers
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        history.push_back(tweetId);
        mp1[tweetId] = userId;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for (auto i = history.rbegin(); i != history.rend() && ans.size() < 10; ++i) {
            // check that post is from someone who user follows +
            // feed must include own post!!
            if (mp2[userId].find(mp1[*i]) != mp2[userId].end() || mp1[*i] == userId) {
                ans.push_back(*i);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp2[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp2[followerId].erase(followeeId);        
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