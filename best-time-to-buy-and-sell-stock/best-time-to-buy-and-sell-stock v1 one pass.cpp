class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans=0,curMin=INT_MAX;
      for(int p:prices){
        curMin=min(curMin,p);
        ans=max(ans,p-curMin);
      }
      return ans;
    }
};
