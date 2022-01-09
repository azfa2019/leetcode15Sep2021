class Solution {
    public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int ans=0;
        while(left<right){
            int area=min(height[left],height[right])*(right-left);
            ans=max(ans,area);
            if(height[left]<height[right]){
                int l=height[left];
                while(left<right && height[left]<=l) left++;
            }else {
                int r=height[right];
                while(left<right && height[right]<=r)  right--;
            }
        }
        return ans;
    }
};