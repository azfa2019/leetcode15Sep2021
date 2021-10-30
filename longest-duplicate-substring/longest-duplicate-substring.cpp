typedef uint64_t ULL;
class Solution {
  unordered_map<int,int>len2start;
public:
    string longestDupSubstring(string s) {
      int left=1,right=s.size()-1;
      while(left<right){
        int mid=left+(right-left+1)/2;
        if(found(s,mid)) left=mid;
        else right=mid-1;
      }
      if(found(s,left)){
        return s.substr(len2start[left],left);
      }else return "";
    }
  bool found(string&s,int len){
    unordered_set<ULL>set0;
    ULL hash=0;
    ULL powBase=1;
    ULL base=31;
    for(int i=0;i<len-1;i++) powBase*=base;
    for(int i=0;i<s.size();i++){
      if(i>=len)
        hash-=powBase*(s[i-len]-'a');
      hash=hash*base+s[i]-'a';
      if(i>=len-1){
        if(set0.find(hash)!=set0.end()){
          len2start[len]=i-len+1;
          return true;
        }
        set0.insert(hash);
      }
    }
    return false;
  }
};