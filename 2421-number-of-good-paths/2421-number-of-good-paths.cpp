class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int>>g(n);
        for(auto&e: edges) g[e[0]].push_back(e[1]),g[e[1]].push_back(e[0]);
        int id[n],fa[n],size[n];
        iota(id,id+n,0),iota(fa,fa+n,0);
        fill(size,size+n,1);
        function<int(int)> find=[&](int x) -> int{return fa[x]==x?x:fa[x]=find(fa[x]);};
        
        int ans=n;
        sort(id,id+n,[&](int a,int b){ return vals[a]<vals[b]; });
        for(int x:id){
            int vx=vals[x],fx=find(x);
            for(int y:g[x]){
                y=find(y);
                if(y==fx||vals[y]>vx) continue;
                if(vals[y]==vx) ans+=size[fx]*size[y],size[fx]+=size[y];
                fa[y]=fx;
            }
        }
        return ans;
    }
};