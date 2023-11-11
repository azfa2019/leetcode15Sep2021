class Graph {
public:
    const static int N=110,M=N*N,INF=0x3f3f3f3f;
    int h[N],e[M],ne[M],w[M],idx,dist[N];
    bool st[N];
    typedef pair<int,int> PII;
    Graph(int n, vector<vector<int>>& edges) {
        memset(h,-1,sizeof h);
        idx=0;
        for(auto &e: edges) addEdge(e);
    }
    
    void addEdge(vector<int> edge) {
        int a=edge[0],b=edge[1],c=edge[2];
        e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    }
    
    int shortestPath(int n1, int n2) {
        priority_queue<PII,vector<PII>,greater<PII>>heap;
        memset(dist,0x3f,sizeof dist);
        memset(st,0,sizeof st);
        dist[n1]=0;
        heap.push({dist[n1],n1});
        while(heap.size()){
            auto t=heap.top();heap.pop();
            int r=t.second;
            if(st[r]) continue;
            if(r==n2) return dist[n2]==INF?-1:dist[n2];
            st[r]=true;
            for(int i=h[r];~i;i=ne[i]){
                int j=e[i];
                if(dist[j]>dist[r]+w[i]){
                    dist[j]=dist[r]+w[i];
                    heap.push({dist[j],j});
                }
            }
        }
        return dist[n2]==INF?-1:dist[n2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */