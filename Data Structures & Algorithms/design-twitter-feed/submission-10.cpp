class Twitter {
private:
    unordered_map<int,unordered_set<int>>followMap; //key = userID, value = vector of follows
    unordered_map<int,vector<pair<int,int>>> userPosts; //key = userId, value = vector of posts <time,id>
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userPosts[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
        priority_queue<pair<int,int>>maxHeap;
        int indexFromBack = 0;
        vector<int> feed;
        for (int i = 0; i < 10; ++i){
            for (auto user : followMap[userId]){
                vector<pair<int,int>> &posts = userPosts[user];
                int index = posts.size()-1-indexFromBack;
                if (index >= 0) maxHeap.push(posts[index]);
                    
            }
            indexFromBack++;
            if (maxHeap.empty())break;
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId==followeeId) return;
        followMap[followerId].erase(followeeId);
    }
};
