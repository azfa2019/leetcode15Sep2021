class Solution {
public:
    vector<int>p;
        int find(int x){
            if(p[x]!=x) p[x]=find(p[x]);
            return p[x];
        }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        p.resize(n+1);
        for(int i=1;i<=n;i++) p[i]=i;
        p[firstPerson]=0;
        map<int,vector<vector<int>>>hash;
        for(auto& m:meetings){
            hash[m[2]].push_back({m[0],m[1]});
        }
        for(auto h:hash){
            auto meet=h.second;
            for(auto& l:meet){
                int a=l[0],b=l[1];
                if(p[find(a)]==0||p[find(b)]==0){
                    p[find(a)]=0;
                    p[find(b)]=0;
                }
                p[find(a)]=p[find(b)];
            }
            for(auto& l:meet){
                int a=l[0],b=l[1];
                if(p[find(a)]==0||p[find(b)]==0){
                    p[find(a)]=0;
                    p[find(b)]=0;
                }else{
                    p[a]=a;
                    p[b]=b;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
            if(p[find(i)]==0) ans.push_back(i);
        return ans;
    }
};