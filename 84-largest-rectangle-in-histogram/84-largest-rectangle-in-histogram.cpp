class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int n=heights.size();
        vector<int>nextSmall(n,n);
        for(int i=0;i<n;i++){
            while(stk.size() && heights[stk.top()]>heights[i]) {
                nextSmall[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop(); 
        vector<int>prevSmall(n,-1);
        for(int i=n-1;i>=0;i--){
            while(stk.size() && heights[stk.top()]>heights[i]){
                prevSmall[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=prevSmall[i]+1;
            int r=nextSmall[i]-1;
            ans=max(ans,(r-l+1)*heights[i]);
        }
        return ans;
    }
};