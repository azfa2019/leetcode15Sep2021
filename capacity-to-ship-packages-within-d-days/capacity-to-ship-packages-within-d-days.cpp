class Solution {
  int n;
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int left=INT_MIN,right=0;
      n=weights.size();
      for(int w:weights){
        left=max(left,w);
        right+=w;
      }
      while(left<right){
        int mid=left+(right-left)/2;
        if(check(weights,days,mid)) right=mid;
        else left=mid+1;
      }
      return left;
    }
  bool check(vector<int>& weights, int days,int cap){
    int count=0;
    for(int i=0;i<n;i++){
      int j=i;
      int sum=0;
      while(j<n && sum+weights[j]<=cap){
        sum+=weights[j];
        j++;
      }
      count++;
      if(count>days) return false;
      i=j-1;
    }
    return true;
  }
};