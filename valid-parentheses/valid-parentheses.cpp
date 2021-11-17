class Solution {
  public:
  bool isValid(string s) {
    stack<char>stack0;
    for(char c:s){
      if(c=='('||c=='['||c=='{') stack0.push(c);
      if(c==')') {
        if(stack0.empty() || stack0.top()!='(') return false;
        stack0.pop();
      }else if(c==']') {
        if(stack0.empty() ||stack0.top()!='[') return false;
        stack0.pop();
      }else if(c=='}') {
        if(stack0.empty() ||stack0.top()!='{') return false;
        stack0.pop();
      }
    }
    return stack0.size()==0;
  }
};