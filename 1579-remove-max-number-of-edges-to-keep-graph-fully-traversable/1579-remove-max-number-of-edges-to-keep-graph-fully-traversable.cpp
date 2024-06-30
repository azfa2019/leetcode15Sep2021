class Solution {
public:
    vector<int>par;
    int cnt;
    int getroot(int x){
        int root=x;
        while(par[root]!=root) root=par[root];
        while(par[x]!=root){
            int tmp=par[x];
            par[x]=root;
            x=tmp;
        }
        return root;
    }
    void merge(int x,int y){
        int px=getroot(x),py=getroot(y);
        if(px!=py) par[px]=py,cnt--;
    }
    void init(int n){
        cnt=n;
        for(int i=1;i<=n;i++) par[i]=i;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        par=vector<int>(n+1);
        int ans=0;
        int cnt1=0,cnt2=0,cnt3=0;
        init(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1||edges[i][0]==3)
                merge(edges[i][1],edges[i][2]),cnt1++;
        }
        if(cnt!=1) return -1;
        init(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==2||edges[i][0]==3)
                merge(edges[i][1],edges[i][2]),cnt2++;
        }
        if(cnt!=1) return -1;
        init(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3)
                merge(edges[i][1],edges[i][2]),cnt3++;
        }
        cnt1-=cnt3,cnt2-=cnt3;
        ans+=(cnt3-(n-cnt));
        ans+=cnt1-(cnt-1)+cnt2-(cnt-1);
        return ans;
    }
};