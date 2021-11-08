class Solution {
  int n;
  public:
  int maximizeSweetness(vector<int>& sweetness, int k) {
    n=sweetness.size();
    int sum=0;
    for(int s:sweetness) sum+=s;
    int left=0,right=sum;
    while(left<right){
      int mid=left+(right-left)/2;
      if(check(sweetness,k,mid)) right=mid;
      else left=mid+1;
    }
    return left;
  }
  bool check(vector<int>& sweetness, int k,int val){
    int count=1,sum=0;
    for(int num:sweetness){
      sum+=num;
      if(sum>val){
        sum=0;
        count++;
        if(count>k+1) return false;
      }
    }
    return true;
  }
  bool check1(vector<int>& sweetness, int k,int val){
    int sum=0,count=0;
    for(int i=0;i<n;i++){
      sum+=sweetness[i];
      if(sum>=val){
        count++;
        sum=0;
      }
    }
    return count>=k+1;
  }
};