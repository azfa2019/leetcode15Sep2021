class Solution {
  int n;
  public:
  int maximizeSweetness(vector<int>& sweetness, int k) {
    int sum=0;
    n=sweetness.size();
    for(int s:sweetness) sum+=s;
    int left=0,right=sum;
    while(left<right){
      int mid=left+(right-left+1)/2;
      if(check(sweetness,k,mid)) left=mid;
      else right=mid-1;
    }
    return left;
  }
  bool check(vector<int>& sweetness, int k,int val){
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=sweetness[i];
      if(sum>=val){
        sum=0;
        count++;
      }
    }
    return count>=k+1;
  }
};