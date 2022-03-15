class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n=s.size();
        vector<bool>invalid(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i),invalid[i]=1;
            if(s[i]==')'){
                if(st.empty()) invalid[i]=1;
                else invalid[st.top()]=0, st.pop();
            }
        }
        string res;
        for(int i=0;i<n;i++){
            if(invalid[i]) continue;
            else res+=s[i];
        }
        return res;
    }
};
