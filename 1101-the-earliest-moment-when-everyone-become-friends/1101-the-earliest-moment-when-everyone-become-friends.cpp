class Solution {
public:
    vector<int>p;
    int cnt;
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    void merge(int x,int y){
        int px=find(x),py=find(y);
        if(px!=py) p[px]=py,cnt--;
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        p.resize(n);
        for(int i=0;i<n;i++) p[i]=i;
        cnt=n;
        for(auto& e:logs){
            int t=e[0],x=e[1],y=e[2];
            merge(x,y);
            if(cnt==1) return t;
        }
        return -1;
    }
};