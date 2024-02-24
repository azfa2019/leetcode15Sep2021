class Solution {
public:
    vector<int>f,sz;
    int find(int x){
        return x==f[x]?x:f[x]=find(f[x]);
    }
    void add(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy) return;
        if(sz[fx]<sz[fy]){
            f[fx]=fy;
            sz[fy]+=sz[fx];
        }else{
            f[fy]=fx;
            sz[fy]+=sz[fx];
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        f.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++) f[i]=i;
        add(0,firstPerson);
        sort(meetings.begin(),meetings.end(),[&](const vector<int>&m1,const vector<int>&m2){
            return m1[2]<m2[2];
        });
        int last=0;
        int m=meetings.size();
        for(int i=1;i<=m;i++){
            if(i<m && meetings[i][2]==meetings[i-1][2]) continue;
            for(int j=last;j<i;j++){
                int x=meetings[j][0],y=meetings[j][1];
                add(x,y);
            }
            for(int j=last;j<i;j++){
                int x=meetings[j][0],y=meetings[j][1];
                if(find(x)==find(0)) continue;
                f[x]=x,sz[x]=1;
                f[y]=y,sz[y]=1;
            }
            last=i;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
            if(find(i)==find(0)) ans.push_back(i);
        return ans;
    }
};