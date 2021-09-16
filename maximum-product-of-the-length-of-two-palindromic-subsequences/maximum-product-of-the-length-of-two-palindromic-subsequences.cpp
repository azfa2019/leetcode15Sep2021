class Solution {
  public:
  int maxProduct(string s) {
    int n=s.size(),m=1<<n; //m: total # of states
    vector<pair<int,int>>list; //list saves all possible palindromic subsequences
    for(int i=1;i<m;i++){
      if(check(s,i)) 
        list.push_back({i,__builtin_popcount(i)});
    }
    int res=0,len=list.size();
    for(int i=0;i<len;i++){
      int x=list[i].first,lenx=list[i].second;
      for(int j=i+1;j<len;j++){
        int y=list[j].first,leny=list[j].second;
        if((x&y)==0) res=max(res,lenx*leny);
      }
    }
    return res;
  }
  bool check(string& s,int state){
    int left=0,right=s.size()-1;
    while(left<right){
      while(left<right&&(state&(1<<left))==0) left++;
      while(left<right&&(state&(1<<right))==0) right--;
      if(s[left]!=s[right]) return false;
      left++,right--;
      }
    return true;
  }

};