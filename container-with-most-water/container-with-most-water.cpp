class Solution {
  public:
  int maxArea(vector<int>& height) {
    int n=height.size();
    int left=0,right=n-1;
    int maxArea=-1;
    while(left<right){
      int lh=height[left],rh=height[right];
      int area=min(lh,rh)*abs(left-right);
      maxArea=max(maxArea,area);
      if(lh<rh){
        while(left<right && lh>=height[left]) left++;
      }else{
        while(left<right && rh>=height[right]) right--;
      }
    }
    return maxArea;
  }
};
//i : j
//i : j+1