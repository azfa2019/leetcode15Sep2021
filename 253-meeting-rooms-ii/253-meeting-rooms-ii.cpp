class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>>all;
        for(auto item:intervals){
            all.push_back({item[0],1});
            all.push_back({item[1],-1});
        }
        int ans=0,count=0;
        sort(all.begin(),all.end());
        for(auto item:all){
            count+=item.second;
            ans=max(ans,count);
        }
        return ans;
    }
};