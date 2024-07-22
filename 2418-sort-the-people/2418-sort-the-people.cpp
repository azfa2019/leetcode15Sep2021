class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size(),id[n];
            
        iota(id,id+n,0);
        sort(id,id+n,[&](const auto&i, const auto&j){
            return heights[i]>heights[j];
        });
        vector<string>ans(n);
        for(int i=0;i<n;i++) ans[i]=names[id[i]];
        return ans;
    }
};