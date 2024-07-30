class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>s1(n+1,0),f(n+1,0);
        for(int i=1;i<=n;i++)
            s1[i]=s1[i-1]+(s[i-1]=='b'?1:0);
        s=' '+s;
        f[0]=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='b') f[i]=f[i-1];
            else f[i]=min(f[i-1]+1,s1[i]);
        }
        return f[n];
    }
};