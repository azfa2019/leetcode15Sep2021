class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int n=g.size(),res=0;
        vector<int> maxpos(3,n);
        for(int i=0;i<n;i++){
            res+=g[i].size();
            if(g[i].find('G')!=-1) maxpos[0]=i;
            if(g[i].find('M')!=-1) maxpos[1]=i;
            if(g[i].find('P')!=-1) maxpos[2]=i;
        }
        for(int i=0;i<3;i++)
            if(maxpos[i]!=n) res+=accumulate(t.begin(),t.begin()+maxpos[i],0);
        return res;
    }
};