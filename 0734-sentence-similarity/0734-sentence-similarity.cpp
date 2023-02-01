class Solution {
public:
    bool areSentencesSimilar(vector<string>& s1, vector<string>& s2, vector<vector<string>>& pairs) {
        if(s1.size()!=s2.size()) return false;
        int n=s1.size();
        unordered_map<string,unordered_set<string>>hash;
        for(auto& p:pairs) {
            hash[p[0]].insert(p[1]);
            hash[p[1]].insert(p[0]);
        }
        for(int i=0;i<n;i++)
            if(s1[i]!=s2[i]&&!hash[s1[i]].count(s2[i])&&!hash[s2[i]].count(s1[i])) return false;
        return true;
    }
};