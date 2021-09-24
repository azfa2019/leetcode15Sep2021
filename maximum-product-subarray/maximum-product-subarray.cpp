class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
      int numMax=1,numMin=1;
      int prevMax=1,prevMin=1;
      int ans=nums[0];
      for(int i=0;i<n;i++){
        int num=nums[i];
        numMax=max(num,max(prevMax*num,prevMin*num));
        numMin=min(num,min(prevMin*num,prevMax*num));
        //cout<<i<<","<<numMax<<","<<numMin<<endl;
        ans=max(ans,max(numMax,numMin));
        prevMax=numMax;
        prevMin=numMin;
      }
      return ans;
    }
};