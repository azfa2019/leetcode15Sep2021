class Solution {
public:
    vector<int>f;
    vector<int>w;
    int n;
    int candy(vector<int>& ratings) {
        n=ratings.size();
        w=ratings;
        f.resize(n,-1);
        int res=0;
        for(int i=0;i<n;i++) res+=dp(i);
        return res;
    }
    int dp(int x){
        if(f[x]!=-1) return f[x];
        f[x]=1;
        if(x && w[x]>w[x-1]) f[x]=max(dp(x-1)+1,f[x]);
        if(x+1<n && w[x]>w[x+1]) f[x]=max(f[x],dp(x+1)+1);
        return f[x];
    }
};