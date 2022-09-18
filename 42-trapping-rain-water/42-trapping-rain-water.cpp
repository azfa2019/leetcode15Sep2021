class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>stk;
        int res=0;
        for(int i=0;i<height.size();i++){
            int last=0;
            while(stk.size()&&height[stk.top()]<=height[i]){
                res+=(height[stk.top()]-last)*(i-stk.top()-1);
                last=height[stk.top()];
                stk.pop();
            }
            if(stk.size()) res+=(i-stk.top()-1)*(height[i]-last);
            stk.push(i);
        }
        return res;
    }
};