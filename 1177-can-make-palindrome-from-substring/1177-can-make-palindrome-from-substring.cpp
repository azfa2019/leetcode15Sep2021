class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        int n=s.size(),m=q.size(),cnt[n+1];
        cnt[0]=0;
        vector<bool>ans(m);
        for(int i=0;i<n;i++){
            int bit=1<<(s[i]-'a');
            cnt[i+1]=cnt[i]^bit;
        }
        for(int i=0;i<m;i++){
            int l=q[i][0],r=q[i][1],k=q[i][2];
            int cur=__builtin_popcount(cnt[r+1]^cnt[l]);
            ans[i]=cur/2<=k;
        }
        return ans;
    }
};