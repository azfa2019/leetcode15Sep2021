class Leaderboard {
    map<int,int>mp;
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
        int res=0;
        int c=0;
        for(auto it=st.rbegin();it!=st.rend() && c<K;it++){
            res+=(it->first);
            c++;
        }
        return res;
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