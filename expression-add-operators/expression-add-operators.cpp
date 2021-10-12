class Solution {
  vector<string> ans;
  public:
  vector<string> addOperators(string num, int target) {
    dfs(num,target,0,"",0,0);
    return ans;
  }
  void dfs(string& num, int& target,int curPos,string preStr,long preVal,long lastTerm){
    //1+2+3+4
    //1+2+3-4
    //1+2+3*4
    if(curPos==num.size()){
      if(preVal==target) ans.push_back(preStr);
      return;
    }
    for(int i=curPos+1;i<=num.size();i++){
      string curStr=num.substr(curPos,i-curPos);
      if(curStr.size()>1&&curStr[0]=='0') continue;
      long curVal=stol(curStr);
      if(curPos==0){
        dfs(num,target,i,curStr,curVal,curVal);
      }else{
        dfs(num,target,i,preStr+"+"+curStr,preVal+curVal,curVal);
        dfs(num,target,i,preStr+"-"+curStr,preVal-curVal,-curVal);
        dfs(num,target,i,preStr+"*"+curStr,preVal-lastTerm+lastTerm*curVal,lastTerm*curVal);
      }
    }
  }
};