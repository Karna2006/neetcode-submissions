class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetmap;
    unordered_map<int, set<int>> followmap;
public:
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare=[](const vector<int>&a, const vector<int>&b){
            return a[0]<b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)>minheap(compare);

        followmap[userId].insert(userId);
        for(int followId:followmap[userId]){
            if(tweetmap.count(followId)){
                const vector<vector<int>>& tweets= tweetmap[followId];
                int ind= tweets.size()-1;
                minheap.push({tweets[ind][0],tweets[ind][1],followId,ind});
            }
        }

        while(!minheap.empty() && res.size()<10){
            vector<int> curr= minheap.top();
            minheap.pop();
            res.push_back(curr[1]);
            int index=curr[3];
            if(index>0){
                const vector<int>& tweet = tweetmap[curr[2]][index-1];
                minheap.push({tweet[0],tweet[1],curr[2],index-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
