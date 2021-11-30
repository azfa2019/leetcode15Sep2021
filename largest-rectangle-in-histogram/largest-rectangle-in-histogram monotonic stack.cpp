class Solution {
  public:
  int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    stack<int>stack;
    stack.push(-1);
    int ans=0;
    for(int i=0;i<n;i++){
      while(stack.top()!=-1 && heights[stack.top()]>=heights[i]){
        int tmp=heights[stack.top()];stack.pop();
        ans=max(ans,tmp*(i-stack.top()-1));
      }
      stack.push(i);
    }
    while(stack.top()!=-1){
      int tmp=heights[stack.top()];stack.pop();
      ans=max(ans,tmp*(n-stack.top()-1));
    }
    return ans;
  }
};
