class Solution {
  public:
  string longestPalindrome(string s) {
    int n=s.size();
    string ans;
    int maxLen=0;
    for(int i=0;i<n;i++){
      int left=i,right=i;
      while(left>=0 && right<=n-1 && s[left]==s[right]){
        if(right-left+1>maxLen) {
          maxLen=right-left+1;
          ans=s.substr(left,maxLen);
        }
        left--;
        right++;
      }
    }
    for(int i=0;i<n-1;i++){
      if(s[i]==s[i+1]){
        int left=i,right=i+1;
        while(left>=0 && right<=n-1 && s[left]==s[right]){
          if(right-left+1>maxLen) {
            maxLen=right-left+1;
            ans=s.substr(left,maxLen);
          }
          left--;
          right++;
        }
      }
    }
    return ans;
  }
};
// odd
// 0 1 2 3 4 5 6
// b a b x b a c
// l           r

// even
// 0 1 2 3 4 5 6 7
// b a b x x b a c
// l             r