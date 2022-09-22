class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& t) {
        vector<vector<int>>res;
        for(auto inter:intervals){
            if(inter[1]<=t[0]||inter[0]>=t[1]) res.push_back(inter);
            else{
                if(inter[0]<t[0]) res.push_back({inter[0],t[0]});
                if(inter[1]>t[1]) res.push_back({t[1],inter[1]});
            }
        }
        return res;                                      
    }
};