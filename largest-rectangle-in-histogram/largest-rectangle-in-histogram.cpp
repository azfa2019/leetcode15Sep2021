class Solution {
  public:
  int largestRectangleArea(vector<int>& heights) {
    int ans=0;
    stack<int>stack;
    stack.push(-1);
    int n=heights.size();
    for( int i=0;i<n;i++){
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