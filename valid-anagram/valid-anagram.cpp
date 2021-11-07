class Solution {
  public:
  bool isAnagram(string s, string t) {
    int m=s.size(),n=t.size();
    if(m!=n) return false;
    vector<int>count(26,0);
    for(char c:s) count[c-'a']++;
    for(char c:t) count[c-'a']--;
    for(int i:count) if(i!=0) return false;
    return true;
  }
};