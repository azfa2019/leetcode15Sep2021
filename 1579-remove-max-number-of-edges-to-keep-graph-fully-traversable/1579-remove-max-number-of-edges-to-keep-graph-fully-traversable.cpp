struct DSU{
    int f[100005];
    int N;
    void init(int n){
        N=n;
        for(int i=1;i<=n;i++) f[i]=i;
    }
    int find(int x){
        if(f[x]!=x) f[x]=find(f[x]);
        return f[x];
    }
    bool merge(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy) return false;
        f[fx]=fy;
        N--;
        return true;
    }
}a,b;
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        a.init(n),b.init(n);
        int ans=0;
        for(auto& e:edges){
            if(e[0]==3){
                bool ba=a.merge(e[1],e[2]);
                bool bb=b.merge(e[1],e[2]);
                if(!ba && !bb) ans++;
            }
        }
        for(auto& e:edges){
            if(e[0]==1 && !a.merge(e[1],e[2])) ans++;
            if(e[0]==2 && !b.merge(e[1],e[2])) ans++;
        }
        if(a.N>1 || b.N>1) return -1;
        return ans;
    }
};