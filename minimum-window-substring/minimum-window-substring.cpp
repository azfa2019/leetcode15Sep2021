class Solution {
  public:
  string minWindow(string s, string t) {
    int n=s.size();
    unordered_map<char,int>map0;
    for(char c:t) map0[c]++;
    int left=0;
    int minLen=INT_MAX;
    string ans;
    int count=0;
    for(int right=0;right<n;right++){
      char r=s[right];
      if(map0.find(r)!=map0.end()) {
        map0[r]--;
        if(map0[r]==0) count++;
      }
      while(count==map0.size()){
        if(minLen>right-left+1){
          minLen=right-left+1;
          ans=s.substr(left,minLen);
        }
        char l=s[left];
        left++;
        if(map0.find(l)!=map0.end()){
          if(map0[l]==0) count--;
          map0[l]++;
        }
      }
    }
    return ans;
  }
};