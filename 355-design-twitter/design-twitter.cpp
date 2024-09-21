class Twitter {
public:
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int tweetCount;
    Twitter() { tweetCount = 0; }

    void postTweet(int userId, int tweetId) {
        tweetCount++;
        tweets[userId].push_back(make_pair(tweetId, tweetCount));
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (auto j : tweets[userId]) {
            pq.push(make_pair(j.second, j.first));
        }
        if (follows.count(userId)) {
            for (const int& followeeId : follows[userId]) {
                for (const auto& tweet : tweets[followeeId]) {
                    pq.push({tweet.second, tweet.first});
                }
            }
        }
        vector<int> ans;
        int count = 0;
        while (count < 10 && !pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            count++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        // if(follows[followerId] > ){
        //     follows[followerId].second = true;
        // }
        if (followerId != followeeId) { // Users cannot follow themselves.
            follows[followerId].insert(followeeId);
        }
       
    }

    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId)) {
            follows[followerId].erase(followeeId);
        }
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