class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        s=' '+s;
        vector<int>f(n+1);
        f[0]=1;
        for(int i=1;i<=n;i++){
            if(valid(i,i,s)) f[i]+=f[i-1];
            if(valid(i-1,i,s)) f[i]+=f[i-2];
        }
        return f[n];
    }
    bool valid(int u,int v,string s){
        if(u<0) return 0;
        if(s[u]=='0') return 0;
        int res=0;
        for(int i=u;i<=v;i++){
            res=res*10+s[i]-'0';
        }
        return res>=1 && res<=26;
    }
};