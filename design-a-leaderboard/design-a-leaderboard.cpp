class Leaderboard {
    unordered_map<int,int>mp;
    set<pair<int,int>>st;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        st.erase({mp[playerId],playerId});
        mp[playerId]+=score;
        st.insert({mp[playerId],playerId});
    }
    
    int top(int K) {
        int ans=0;
        int ct=0;
        for(auto it=st.rbegin();it!=st.rend() && ct<K;it++){
            ans+=it->first;
            ct++;
        }
        return ans;
    }
    
    void reset(int playerId) {
        st.erase({mp[playerId],playerId});
        mp[playerId]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */