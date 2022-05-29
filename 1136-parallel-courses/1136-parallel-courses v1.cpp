class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& r) {
        vector<int>d(n+1);
        vector<vector<int>>g(n+1);
        for(auto e:r){
            int a=e[0],b=e[1];
            d[b]++;
            g[a].push_back(b);
        }
        queue<int>q;
        vector<int>res;
        for(int i=1;i<=n;i++) 
            if(d[i]==0) q.push(i);
        int cnt=0;
        while(q.size()){
            int l=q.size();
            while(l--){
                int t=q.front();q.pop();
                res.push_back(t);
                for(auto ne:g[t]){
                    d[ne]--;
                    if(!d[ne]) q.push(ne);
                }
            }
            cnt++;
        }
        if(res.size()!=n) return -1;
        return cnt;
    }
};
