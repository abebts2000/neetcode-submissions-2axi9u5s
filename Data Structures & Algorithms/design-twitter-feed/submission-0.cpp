struct Tweet
{
    int tweetId;
    int time;
};

struct User
{
    int userId;
    unordered_set<int> follows_;
    vector<Tweet> tweets_;
};

class Twitter {
    unordered_map<int, User> users_;
    int timer;
public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        users_[userId].userId = userId;
        users_[userId].tweets_.push_back({tweetId, timer++});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto& user = users_[userId];
        vector<Tweet> candidates = user.tweets_;
        for(int followeeId : user.follows_) {
            if (followeeId == userId) continue;
            for(auto& t : users_[followeeId].tweets_) {
                candidates.push_back(t);
            }
        }
        sort(candidates.begin(), candidates.end(), [](const Tweet& a, const Tweet& b) {
            return a.time > b.time;
        });
        vector<int> res;
        for(int i = 0; i < (int)candidates.size() && res.size() < 10; i++) {
            res.push_back(candidates[i].tweetId);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        users_[followerId].userId = followerId;
        users_[followerId].follows_.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(users_.find(followerId) != users_.end())
            users_[followerId].follows_.erase(followeeId);
    }
};