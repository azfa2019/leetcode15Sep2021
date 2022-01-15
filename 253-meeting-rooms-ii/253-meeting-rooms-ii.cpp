class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>>all;
        for(auto item:intervals){
            all.push_back({item[0],1});
            all.push_back({item[1],-1});
        }
        sort(all.begin(),all.end());
        int ans=0;
        int count=0;
        for(auto item:all){
            count+=item.second;
            ans=max(ans,count);
        }
        return ans;
    }
};