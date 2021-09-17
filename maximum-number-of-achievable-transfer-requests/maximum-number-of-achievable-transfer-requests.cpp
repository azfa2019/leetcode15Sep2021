class Solution {
  public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int m=(1<<requests.size());
    int ans=0;
    for(int state=0;state<m;state++){
      bool flag=false;
      //vector<int>peopleInBuilding(n,0);
      int peopleInBuilding[n];
      for(int i=0;i<n;i++) peopleInBuilding[i]=0;
      for(int i=0;i<requests.size();i++){
        if((state&(1<<i))==0) continue;
        peopleInBuilding[requests[i][0]]--;
        peopleInBuilding[requests[i][1]]++;
      }
      for(int i:peopleInBuilding) if(i!=0){
        flag=true;
        break;
      }
      if(flag==true) continue;
      ans=max(ans,__builtin_popcount(state));
    }
    return ans;
  }
};
