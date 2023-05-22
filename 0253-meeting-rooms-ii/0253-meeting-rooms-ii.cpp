class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<>>heap;
        sort(intervals.begin(),intervals.end());
        for(auto& inter:intervals){
            if(heap.empty()||inter[0]<heap.top()) heap.push(inter[1]);
            else{
                heap.pop();
                heap.push(inter[1]);
            }
        }
        return heap.size();
    }
};