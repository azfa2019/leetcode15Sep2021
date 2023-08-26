class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int res=0;
        int ed=-2e9;
        for(auto& p:pairs){
            if(ed<p[0]) res++,ed=p[1];
        }
        return res;
    }
};