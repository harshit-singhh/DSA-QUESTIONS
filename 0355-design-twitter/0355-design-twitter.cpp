class Node{
    public:
    int userId;
    int tweetId;
    Node*next;

    Node(int Uid , int Tid){
        this -> userId = Uid;
        this -> tweetId = Tid;
        this -> next = NULL;
    }
};

class Twitter {
    Node*head;

    unordered_map<int , unordered_set<int>>follower;
public:
    Twitter() {
        head = new Node(-1 , -1);
    }
    
    void postTweet(int userId, int tweetId) {
        Node*temp = new Node(userId , tweetId);
        temp -> next = head -> next;
        head -> next = temp;
    }
    
    vector<int> getNewsFeed(int userId) {
        Node*temp = head->next;
        vector<int>ans;
        int counter = 0;

        while(temp != NULL){
            if(temp -> userId == userId || (follower.find(userId) != follower.end() && 
            follower[userId].find(temp -> userId) != follower[userId].end())){
                ans.push_back(temp -> tweetId);
                counter++;
            }
            temp = temp -> next;
            if(counter == 10) break;
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
        
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





//  class Twitter {
//     private:
//     int timer = INT_MAX;
//     // used id - and its friends
//     unordered_map<int,unordered_set<int>>friends;

//     //timer , {userd id , tweet id};
//     map<int , pair<int,int>> news;
// public:
//     Twitter() {
        
//     }
    
//     void postTweet(int userId, int tweetId) {
//         news[timer] = {userId , tweetId};
//         timer--;
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         vector<int>ans;
//         int counter = 10;
//         for(auto it: news){
//             int timer = it.first;
//             int user = it.second.first;
//             int tweetId = it.second.second;

//             if(userId == user || (friends.find(userId) != friends.end() 
//             && friends[userId].find(user) != friends[userId].end())){
//                 ans.push_back(tweetId);
//                 counter--;
//             }
//             if(counter == 0) break;

//         }

//         return ans;
//     }
    
//     void follow(int followerId, int followeeId) {
//         friends[followerId].insert(followeeId);
//     }
    
//     void unfollow(int followerId, int followeeId) {
//         friends[followerId].erase(followeeId);
//     }
// };