class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int>cnt;
        vector<int> pos(26,1e6);
        for(int i=n-1;i>=0;i--){
            cnt[s[i]]++;
            pos[s[i]-'a']=min(pos[s[i]-'a'],i);
        }
        for(int i=0;i<n;i++)
            if(cnt[s[i]]==1) return pos[s[i]-'a'];
        return -1;
    }
};