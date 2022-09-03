class Solution {
public:
    int n,k;
    vector<int>res;
    vector<int> numsSameConsecDiff(int _n, int _k) {
        n=_n,k=_k;
        for(int i=1;i<=9;i++) dfs(1,i);
        return res;
    }
    void dfs(int u,int x){
        if(u==n) res.push_back(x);
        else{
            if(x%10-k>=0) dfs(u+1,x*10+x%10-k);
            if(k&&x%10+k<=9) dfs(u+1,x*10+x%10+k);
        }
    }
};