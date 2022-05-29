class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> d(n);
        vector<vector<int>>g(n);
        for(auto e:p){
            int a=e[1],b=e[0];
            g[a].push_back(b);
            d[b]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0;i<n;i++) 
            if(d[i]==0) q.push(i);
        while(q.size()){
            int t=q.front();q.pop();
            res.push_back(t);
            for(int ne:g[t]){
                d[ne]--;
                if(!d[ne]) q.push(ne);
            }
        }
        if (res.size()!=n) res={};
        return res;
    }
};