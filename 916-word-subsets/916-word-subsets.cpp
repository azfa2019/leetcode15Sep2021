class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>maxcnt;
        for(auto& w:words2) {
            unordered_map<char,int>cnt;
            for(auto c:w) cnt[c]++,maxcnt[c]=max(maxcnt[c],cnt[c]);
            //for(auto [k,v]:cnt) maxcnt[k]=max(maxcnt[k],v);
        }
        vector<string>res;
        for(auto& w:words1){
            unordered_map<char,int>cnt;
            for(auto c:w) cnt[c]++;
            bool flag=true;
            for(auto [k,v]:maxcnt)
                if(cnt[k]<v) {
                    flag=false;
                    break;
                }
            if(flag) res.push_back(w);
        }
        return res;
    }
};