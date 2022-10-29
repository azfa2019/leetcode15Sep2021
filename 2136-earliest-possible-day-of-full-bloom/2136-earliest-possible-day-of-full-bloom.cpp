typedef pair<int,int> PII;
bool cmp(PII& a,PII& b){
    return a.first>b.first;
}
class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<PII> all;
        for(int i=0;i<p.size();i++){
            all.push_back({g[i],p[i]});
        }
        sort(all.begin(),all.end(),cmp);
        int ans=0,ed=0;
        for(auto& item:all){
            int gt=item.first,pt=item.second;
            ed+=pt;
            ans=max(ans,ed+gt);
        }
        return ans;
    }
};