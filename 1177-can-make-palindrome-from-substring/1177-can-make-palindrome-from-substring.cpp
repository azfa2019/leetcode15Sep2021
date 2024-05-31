class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size(),q=queries.size();
        vector<vector<int>>sum(n+1,vector<int>(26));
        for(int i=0;i<n;i++){
            sum[i+1]=sum[i];
            sum[i+1][s[i]-'a']++;
        }
        vector<bool>ans(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0],r=queries[i][1],k=queries[i][2],cnt=0;
            for(int j=0;j<26;j++)
                cnt+=(sum[r+1][j]-sum[l][j])%2;
            if(cnt/2<=k) ans[i]=true;
        }
        return ans;
    }
};