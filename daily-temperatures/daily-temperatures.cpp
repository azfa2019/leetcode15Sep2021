class Solution {
  public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int>ans(n,0);
    stack<int>stack0;
    for(int i=0;i<n;i++){
      while(!stack0.empty() && temperatures[i]>temperatures[stack0.top()]){
        int tmp=stack0.top();
        stack0.pop();
        ans[tmp]=i-tmp;
      }
      stack0.push(i);
    }
    return ans;
  }
};
// 73
// 73 74