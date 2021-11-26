
class Solution {
  public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    int n=intervals.size();
    vector<int>start,end;
    for(auto e:intervals){
      start.push_back(e[0]);
      end.push_back(e[1]);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=0,j=0,ans=0;
    int count=0;
    while(i<n && j<n){
      if(start[i]<end[j]) {
        count++;
        ans=max(ans,count);
        i++;
      }else{
        count--;
        j++;
      }
    }
    return ans;
  }
};
