class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>start,end;
        for(auto item:intervals){
            start.push_back(item[0]);
            end.push_back(item[1]);
        }
        int i=0,j=0;
        int ans=0,count=0;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(i<start.size() && j<end.size()){
            if(start[i]<end[j]) count++,i++;
            else count--,j++;
            ans=max(ans,count);
        }
        return ans;
    }
};