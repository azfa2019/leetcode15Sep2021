class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int count=0;
        vector<pair<int,int>>all;
        for(auto e:trips){
            all.push_back({e[1],e[0]});
            all.push_back({e[2],-e[0]});
        }
        sort(all.begin(),all.end());
        for(auto e:all){
            count+=e.second;
            if(count>capacity) return false;
        }
        return true;
    }
};
