class Solution {
public:
    string reverseWords(string s) {
      while(s[0]==' ') s.erase(s.begin());
      while(s.back()==' ') s.pop_back();
      stack<string>st;
      for(int i=0;i<s.size();i++){
        int i0=i;
        while(i<s.size()&&s[i]!=' ') i++;
        st.push(s.substr(i0,i-i0));
        while(s[i]==' ') i++;
        i--;
      }
      string ans="";
      while(!st.empty()){
        ans+=st.top();
        ans+=" ";
        st.pop();
      }
      ans.pop_back();
      return ans;
    }
};