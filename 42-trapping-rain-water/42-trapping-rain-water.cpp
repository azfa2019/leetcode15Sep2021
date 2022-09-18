class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>stk;
        int res=0;
        for(int i=0;i<height.size();i++){
            int last=0;
            while(stk.size()&&height[stk.top()]<=height[i]) {
                res+=(i-1-stk.top())*(height[stk.top()]-last);
                last=height[stk.top()];
                stk.pop();
            }
            if(stk.size()) res+=(i-1-stk.top())*(height[i]-last);
            stk.push(i);
        }
        return res;
    }
};