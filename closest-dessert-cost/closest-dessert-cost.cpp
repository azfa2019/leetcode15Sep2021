class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
      int ans=INT_MAX;
      for(int i:baseCosts){
        int sum=i;
        helper(toppingCosts,sum,target,0,ans);
        if(ans==target) return target;
      }
      return ans;
    }
  void helper(vector<int>& toppingCosts, int sum,int target,int idx,int& ans){
    
    if(abs(sum-target)<abs(ans-target)) ans=sum;
    else if(abs(sum-target)==abs(ans-target)&&sum<ans) ans=sum;
    else if(sum>target) return;
    if(sum==target) return;
    if(idx==toppingCosts.size()) return;
    helper(toppingCosts,sum,target,idx+1,ans);
    helper(toppingCosts,sum+toppingCosts[idx],target,idx+1,ans);
    helper(toppingCosts,sum+2*toppingCosts[idx],target,idx+1,ans);
    
  }
};