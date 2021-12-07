class Solution {
    public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int ans=(n-1)*min(height[0],height[n-1]);
        while(l<r){
            int lh=height[l];
            int rh=height[r];
            ans=max(ans,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r]) 
                while(l<r && lh>=height[l]) l++;
            else 
                while(l<r && rh>=height[r]) r--;
        }
        return ans;
    }
};
