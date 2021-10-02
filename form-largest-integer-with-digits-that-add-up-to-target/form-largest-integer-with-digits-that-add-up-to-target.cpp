class Solution {
  public:
  string largestNumber(vector<int>& cost, int target) {
    cost.insert(cost.begin(),0);
    vector<string>dp(target+1,"");
    //dp[i]: the max number when the total cost is i
    for(int i=1;i<=target;i++){ //unbounded kanpsack, the loop of target is the outer loop to allow repeated use of each item
      dp[i]="#";
      for(int j=1;j<=9;j++){
        if(i-cost[j]<0 || dp[i-cost[j]]=="#") continue;
        string candidate=dp[i-cost[j]]+to_string(j);
        if(dp[i].size()<candidate.size() || (dp[i].size()==candidate.size() && dp[i]<candidate))
          dp[i]=candidate;
      }
    }
    return dp[target]=="#"?"0":dp[target];
  }
};