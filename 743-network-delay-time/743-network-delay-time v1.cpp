const int N=110,M=6010,INF=0x3f3f3f3f;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];
class Solution {
    void add(int a,int b,int c){
        e[idx]=b,w[idx]=c;ne[idx]=h[a],h[a]=idx++;
    }
    void spfa(int start){
        queue<int>q;
        q.push(start);
        memset(dist,0x3f,sizeof dist);
        dist[start]=0;
        while(q.size()){
            int t=q.front();q.pop();
            st[t]=false;
            for(int i=h[t];~i;i=ne[i]){
                int j=e[i];
                if(dist[j]>dist[t]+w[i]){
                    dist[j]=dist[t]+w[i];
                    if(!st[j]) st[j]=true,q.push(j);
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(h,-1,sizeof h);
        //dist[k]=0;
        idx=0;
        for(auto item:times){
            int a=item[0],b=item[1],c=item[2];
            add(a,b,c);
        }
        spfa(k);
        int res=0;
        for(int i=1;i<=n;i++){
            res=max(res,dist[i]);
        }
        if(res==INF) res=-1;
        return res;
    }
};
