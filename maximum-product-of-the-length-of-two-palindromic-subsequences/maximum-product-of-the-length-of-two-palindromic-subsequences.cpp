class Solution {
  public:
  int maxProduct(string s) {
    int n=s.size();
    int m=(1<<n); //# of states
    vector<pair<int,int>>list;//saves all palindromic subsequences, first: state; second=# of 1s, or the length of the palindrome

    for(int i=1;i<m;i++){
      if(check(s,i)) list.push_back({i,__builtin_popcount(i)});
    }

    int len=list.size();
    int res=0;
    for(int i=0;i<len;i++){
      int x=list[i].first,lenx=list[i].second;
      for(int j=i+1;j<len;j++){
        int y=list[j].first,leny=list[j].second;
        if((x&y)==0) res=max(res,lenx*leny);
      }
    }
    return res;
  }
  bool check(string&s,int state){
    int left=0,right=s.size()-1;
    while(left<right){
      while(left<right && (state&(1<<left))==0) left++;
      while(left<right && (state&(1<<right))==0) right--;
      if(s[left]!=s[right]) return false;
      left++,right--;
    }
    return true;
  }
};