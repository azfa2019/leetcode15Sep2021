class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>win,lose;
        map<int,int>mlose;
        for(auto m:matches){
            mlose[m[0]];
            mlose[m[1]]++;
        }
        for(auto it=mlose.begin();it!=mlose.end();it++) {
            if(it->second==0) win.push_back(it->first);
            if(it->second==1) lose.push_back(it->first);
        }
        return vector<vector<int>>{win,lose};
    }
};