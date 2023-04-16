typedef long L;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        L mod=1e9+7;
        int n=words[0].size(),m=target.size();
        int cnt[n][26];
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<n;i++)
            for(auto& w:words)
                cnt[i][w[i]-'a']++;
        L d[n][m];
        memset(d,0,sizeof d);
        d[0][0]=cnt[0][target[0]-'a'];
        for(int i=1;i<n;i++){
            d[i][0]=d[i-1][0]+cnt[i][target[0]-'a']%mod;
            for(int j=1;j<m;j++)
                d[i][j]=(d[i-1][j]+d[i-1][j-1]*cnt[i][target[j]-'a'])%mod;
        }
        return d[n-1][m-1];   
    }
};