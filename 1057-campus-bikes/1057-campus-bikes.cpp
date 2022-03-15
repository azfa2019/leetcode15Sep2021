class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n=workers.size(),m=bikes.size();
        vector<bool>assigned(n);
        vector<bool>taken(m);
        vector<vector<pair<int,int>>>list(2001);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int dist=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                list[dist].push_back({i,j});
            }
        vector<int>res(n);
        for(int i=0;i<2001;i++){
            if(!list[i].size()) continue;
            for(int j=0;j<list[i].size();j++){
                int w=list[i][j].first,b=list[i][j].second;
                if(!assigned[w] && !taken[b]){
                    res[w]=b;
                    assigned[w]=true;
                    taken[b]=true;
                }
            }
        }
        return res;
    }
};