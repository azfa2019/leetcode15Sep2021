class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>stck;
        stck.push(-1); //to calculate the border of the first element
        int ans=0;
        for(int i=0;i<n;i++){
            while(stck.top()!=-1 && heights[stck.top()]>=heights[i]){
                int cur=heights[stck.top()];stck.pop();
                int leftBoundary=stck.top();
                ans=max(ans,cur*(i-leftBoundary-1));
            }
            stck.push(i);
        }
        while(stck.top()!=-1){
            int cur=heights[stck.top()];stck.pop();
            int leftBoundary=stck.top();
            ans=max(ans,(n-leftBoundary-1)*cur);
        }
        return ans;
    }
};