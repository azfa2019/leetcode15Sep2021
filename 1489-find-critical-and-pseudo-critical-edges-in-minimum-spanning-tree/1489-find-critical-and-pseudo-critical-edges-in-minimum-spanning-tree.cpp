class Solution {
public:
    vector<int>p;
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    int kruskalNoK(int n,vector<vector<int>>& edges,int k){
        for(int i=0;i<n;i++) p[i]=i;
        int res=0,cnt=n;
        for(auto& e:edges){
            int w=e[0],a=e[1],b=e[2],i=e[3];
            if(i==k) continue;
            if(find(a)!=find(b)){
                p[find(a)]=find(b);
                res+=w;
                cnt--;
            }
        }
        if(cnt>1) return INT_MAX;
        return res;
    }
        int kruskalK(int n,vector<vector<int>>& edges,int k){
        for(int i=0;i<n;i++) p[i]=i;
        int res=0,cnt=n;
        for(auto& e:edges){
                if(e[3]==k){
                int w=e[0],a=e[1],b=e[2],i=e[3];
                if(find(a)!=find(b)){
                    p[find(a)]=find(b);
                    res+=w;
                    cnt--;
                }
                break;
            }
        }
            for(auto& e:edges){
                int w=e[0],a=e[1],b=e[2],i=e[3];
                if(i==k) continue;
                if(find(a)!=find(b)){
                    p[find(a)]=find(b);
                    res+=w;
                    cnt--;
            }
        }
        if(cnt>1) return INT_MAX;
        return res;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            auto &e=edges[i];
            swap(e[0],e[2]);
            e.push_back(i);
        }
        sort(edges.begin(),edges.end());
        p=vector<int>(n);
        int cost=kruskalNoK(n,edges,-1);
        vector<vector<int>>res(2);
        for(int i=0;i<edges.size();i++){
            if(kruskalNoK(n,edges,i)!=cost) res[0].push_back(i);
            else if(kruskalK(n,edges,i)==cost) res[1].push_back(i);
        }
        return res;
    }
};