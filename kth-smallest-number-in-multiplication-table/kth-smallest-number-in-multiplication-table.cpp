class Solution {
public:
    int findKthNumber(int m, int n, int k) {
      int left=1;
      int right=m*n;
      while(left<right){
        int mid=left+(right-left)/2;
        if(countEqualSmaller(mid,m,n)<k) left=mid+1;
        else right=mid;
      }
      return left;
    }
  int countEqualSmaller(int mid,int m,int n){
    int count=0;
    for(int i=1;i<=m;i++)
      count+=min(mid/i,n);
    return count;
  }
};