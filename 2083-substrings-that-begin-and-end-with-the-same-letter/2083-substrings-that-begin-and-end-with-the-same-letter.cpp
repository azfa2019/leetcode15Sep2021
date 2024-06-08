class Solution {
public:
    long long numberOfSubstrings(string s) {
        int cnt[26]{0};
        long long ans=0;
        //memset(cnt,0,sizeof cnt);
        for(char& c:s){
            ans+=++cnt[c-'a'];
        }
        return ans;
    }
};