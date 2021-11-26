class Solution {
  public:
  bool isAnagram(string s, string t) {
    vector<int>count(26,0);
    for(char c:s){
      count[c-'a']++;
    }
    for(char c:t){
      count[c-'a']--;
    }
    for(auto e:count) if(e!=0) return false;
    return true;
  }
};