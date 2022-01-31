class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto c:accounts){
            int cur=accumulate(c.begin(),c.end(),0);
            ans=max(cur,ans);
        }
        return ans;
    }
};
