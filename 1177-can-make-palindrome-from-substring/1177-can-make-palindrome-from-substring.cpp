class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        int n=s.size(),m=q.size();
        vector<vector<int>>cnt(n+1,vector<int>(26));
        for(int i=0;i<n;i++){
            cnt[i+1]=cnt[i];
            cnt[i+1][s[i]-'a']++;
        }
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int l=q[i][0],r=q[i][1],k=q[i][2],sum=0;
            for(int j=0;j<26;j++){
                sum+=((cnt[r+1][j]-cnt[l][j])%2==1);
            }
            ans[i]=(sum/2<=k);
        }
        return ans;
    }
};