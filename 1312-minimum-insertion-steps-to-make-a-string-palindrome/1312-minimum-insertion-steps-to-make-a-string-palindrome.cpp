class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>f(n,vector<int>(n));
        for(int len=2;len<=n;len++)
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                f[i][j]=min(f[i+1][j],f[i][j-1])+1;
                if(s[i]==s[j]) f[i][j]=min(f[i][j],f[i+1][j-1]);
            }
        return f[0][n-1];
    }
};