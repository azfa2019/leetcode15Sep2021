class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int>cnt;
        for(char&c:s) cnt[c]++;
        for(int i=0;i<n;i++) if(cnt[s[i]]==1) return i;
        return -1;
    }
};