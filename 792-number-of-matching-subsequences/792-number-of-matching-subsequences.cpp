class Solution {
    typedef pair<int,int> PII;
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        vector<PII>ps[26];
        for(int i=0;i<words.size();i++)
            ps[words[i][0]-'a'].push_back({i,0});
        for(char c:s){
            vector<PII>buf;
            for(auto& p:ps[c-'a']){
                if(p.second==words[p.first].size()-1) ans++;
                else buf.push_back({p.first,p.second+1});
            }
            ps[c-'a'].clear();
            for(auto&p:buf) ps[words[p.first][p.second]-'a'].push_back(p);
        }
        return ans;
    }
};