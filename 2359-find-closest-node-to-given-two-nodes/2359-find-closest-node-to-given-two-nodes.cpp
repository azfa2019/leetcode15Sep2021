class Solution {
public:
    vector<int> edges;
    int closestMeetingNode(vector<int>& _edges, int node1, int node2) {
        edges=_edges;
        int n=edges.size();
        vector<int>dist1(n,-1),dist2(n,-1);
        bfs(node1,dist1);
        bfs(node2,dist2);
        //for(int i=0;i<n;i++) cout<<dist1[i]<<"; "<<dist2[i]<<endl;
        int d=1e9,res;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                int maxd=max(dist1[i],dist2[i]);
                if(d>maxd) d=maxd,res=i;
            }
        }
        if(d==1e9) return -1;
        return res;
    }
    void bfs(int n1,vector<int>&dist){
        queue<int>q;
        q.push(n1);
        dist[n1]=0;
        while(q.size()){
            auto t=q.front();q.pop();
            if(edges[t]!=-1){
                int ne=edges[t];
                if(dist[ne]==-1) {
                    dist[ne]=dist[t]+1;
                    q.push(ne);
                }
            }
        }
    }
};