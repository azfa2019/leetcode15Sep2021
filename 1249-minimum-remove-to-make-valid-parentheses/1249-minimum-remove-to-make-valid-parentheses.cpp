class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        string res;
        int n=s.size();
        vector<bool>invalid(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='(') invalid[i]=1,st.push(i);
            else if(s[i]==')'){
                if(st.empty()) invalid[i]=1;
                else {
                    invalid[st.top()]=false;
                    st.pop();
                }
            }
        }
        for(int i=0;i<n;i++){
            if(invalid[i]) continue;
            res+=s[i];
        }
        return res;
    }
};