class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string,string>par;
        for(auto&r:regions){
            auto r0=r[0];
            for(int i=1;i<r.size();i++) par[r[i]]=r0;
        }
        unordered_set<string>ancestors;
        while(region1!="") {
            ancestors.insert(region1);
            region1=par[region1];
        }
        while(!ancestors.count(region2))
            region2=par[region2];
        return region2;
    }
};