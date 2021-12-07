class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int ans=(n-1)*min(height[0],height[n-1]);
        while(l<r){
            //while(l<r && height[l]>=height[l+1]) l++;
            //while(l<r && height[r-1]<=height[r]) r--;
            ans=max(ans,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r]) l++;
            else r--;
        }
        return ans;
    }
};