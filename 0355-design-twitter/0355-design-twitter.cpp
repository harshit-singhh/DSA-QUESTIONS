class Twitter {
    private:
    int timer = INT_MAX;
    // used id - and its friends
    unordered_map<int,unordered_set<int>>friends;

    //timer , {userd id , tweet id};
    map<int , pair<int,int>> news;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        news[timer] = {userId , tweetId};
        timer--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int counter = 10;
        for(auto it: news){
            int timer = it.first;
            int user = it.second.first;
            int tweetId = it.second.second;

            if(userId == user || (friends.find(userId) != friends.end() 
            && friends[userId].find(user) != friends[userId].end())){
                ans.push_back(tweetId);
                counter--;
            }
            if(counter == 0) break;

        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
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