class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftHigh(n,0);
        vector<int>rightHigh(n,0);
        for(int i=1;i<n;i++){
            leftHigh[i]=max(leftHigh[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightHigh[i]=max(rightHigh[i+1],height[i+1]);
        }
        cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            int h=min(leftHigh[i],rightHigh[i])-height[i];
            ans+=max(0,h*1);
        }
        return ans;
    }
};
