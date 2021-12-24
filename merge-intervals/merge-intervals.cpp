class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(auto e:intervals){
            if(ans.size()==0) ans.push_back(e);
            else {
                if(e[0]<=ans.back()[1]) ans.back()[1]=max(ans.back()[1],e[1]);
                else ans.push_back(e);
            }
        }
        return ans;
    }
};