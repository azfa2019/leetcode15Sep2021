class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int>stck;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!stck.empty() && height[stck.top()]<height[i] ){
                int base=height[stck.top()];
                stck.pop();
                if(stck.empty()) continue;
                int h=min(height[stck.top()],height[i])-base;
                int w=i-stck.top()-1;
                ans+=h*w;
            }
            stck.push(i);
        }
        return ans;
    }
};
// x          x          x 
// x     x    x o o x    x     x
// x x o x    x x   x    x     x
// x x o x    x x   x    x     x
// x x x x    x x   x    x     x
// x x x x    x x   x    x     x
