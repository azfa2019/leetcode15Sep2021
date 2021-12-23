class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int>eOld={INT_MIN,INT_MIN};
        for(auto e:intervals){
            if(e[0]<eOld[1]) return false;
            eOld=e;
        }
        return true;
    }
};