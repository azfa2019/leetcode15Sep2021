class Solution {
  public:
  int characterReplacement(string s, int k) {
    int right,left=0,maxRep=0;
    int ans=0;
    unordered_map<char,int>map0;
    for(right=0;right<s.size();right++){
      char r=s[right];
      map0[r]++;
      maxRep=max(maxRep,map0[r]);
      if(right-left+1>maxRep+k){
        char l=s[left++];
        map0[l]--;
      }
      ans=max(ans,right-left+1);
    }
    return ans;
  }
};