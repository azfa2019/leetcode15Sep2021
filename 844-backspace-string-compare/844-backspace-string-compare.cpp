class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return extract(s)==extract(t);
    }
    string extract(string& s){
        stack<char>stk;
        for(auto c:s){
            if(c!='#') stk.push(c);
            else {
                if(stk.size()) stk.pop();
            }
        }
        string res="";
        while(stk.size()){
            res=res+stk.top();
            stk.pop();
        }
        return res;
    }
};