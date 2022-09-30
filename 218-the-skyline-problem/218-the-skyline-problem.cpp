class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>res;
        multiset<pair<int,int>>events;
        multiset<int> height;
        height.insert(0);
        int n=buildings.size();
        for(int i=0;i<n;i++){
            events.insert(make_pair(buildings[i][0],-buildings[i][2]));
            events.insert(make_pair(buildings[i][1],buildings[i][2]));
        }
        for(auto p:events){
            if(p.second<0){
                if(-p.second>*height.rbegin()) res.push_back({p.first,-p.second});
                height.insert(-p.second);
            }else{
                height.erase(height.find(p.second));
                if(p.second>*height.rbegin()) res.push_back({p.first,*height.rbegin()});
            }
        }
        return res;
    }
};