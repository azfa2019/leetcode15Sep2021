class Solution {
public:
    vector<int>p;
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    void merge(int x,int y){
        int px=find(x),py=find(y);
        if(px!=py) p[px]=py;
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        p.resize(n);
        for(int i=0;i<n;i++) p[i]=i;
        for(auto& e:logs){
            int t=e[0],x=e[1],y=e[2];
            merge(x,y);
            int px=find(0),flag=1;
            for(int i=1;i<n;i++){
                if(find(i)!=px) {
                    flag=0;
                    break;
                }
            }
            if(flag) return t;
        }
        return -1;
    }
};