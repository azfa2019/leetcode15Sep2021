class Solution {
    struct compare{
        bool operator ()(vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        }
    };
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(auto e:intervals){
            if(!pq.empty() && pq.top()[1]<=e[0]&&pq.top()[1]<=e[1]) pq.pop();
            pq.push(e);
        }
        return pq.size();
    }
};
//0,30  5,10 15,20, 
//