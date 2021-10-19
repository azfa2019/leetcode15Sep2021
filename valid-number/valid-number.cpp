class Solution {
  public:
  bool isNumber(string s) {
    while(s.back()==' ') s.pop_back();
    while(s[0]==' ') s.erase(s.begin());
    if(s=="") return false;
    int countE=0,posE;
    for(int i=0;i<s.size();i++){
      if(s[i]=='e'||s[i]=='E') countE++,posE=i;
    }
    if(countE>1) return false;
    if(countE==0) return isokay(s,1);
    return isokay(s.substr(0,posE),1)&&isokay(s.substr(posE+1),0);
  }
  bool isokay(string s,int k){
    for(int i=0;i<s.size();i++){
      if((s[i]=='+'||s[i]=='-') && i!=0) return false;
    }
    if(s[0]=='+'||s[0]=='-') s.erase(s.begin());
    if(s==""||s==".")return false;
    int countDot=0;
    for(int i=0;i<s.size();i++){
      if(s[i]=='.') countDot++;
      else if(!isdigit(s[i])) return false;
    }
    return countDot<=k;
  }
};