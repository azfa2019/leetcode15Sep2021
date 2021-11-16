class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int p1=0;
      unordered_map<char,int>map0;
      int ans=0;
      int n=s.size();
      for(int p2=0;p2<n;p2++){
        char right=s[p2];
        map0[right]++;
        while(map0[right]>1){
          char left=s[p1];
          map0[left]--;
          if(map0[left]==0) map0.erase(left);
          p1++;
        }
        ans=max(ans,p2-p1+1);
      }
      return ans;
    }
};
//e abca bcbb
//     p2
//     p1
