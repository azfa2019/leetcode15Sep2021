class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal){
            vector<int>cnt(26,0);
            for(auto& c:s){
                cnt[c-'a']++;
                if(cnt[c-'a']>1) return true;
            }
        }
        int n=s.size();
        vector<int>diff;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]) diff.push_back(i);
        }
        if(diff.size()!=2) return false;
        int x=diff[0],y=diff[1];
        if(s[x]==goal[y] && s[y]==goal[x]) return true;
        return false;
    }
};