class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        int n=s.size(),m=q.size(),sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++){
            int bit=1<<(s[i]-'a');
            sum[i+1]=sum[i]^bit;
        }
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int l=q[i][0],r=q[i][1],k=q[i][2],cnt;
            for(int j=0;j<26;j++)
                cnt=__builtin_popcount(sum[r+1]^sum[l]);
            ans[i]=cnt/2<=k;
        }
        return ans;
    }
};