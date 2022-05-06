class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int>stk;
        for(int i=0;i<s.size();i++){
            if(i==0||s[i-1]!=s[i]) stk.push(1);
            else if(++stk.top()==k) {
                    stk.pop();
                    s.erase(i-k+1,k);
                    i-=k;
                }
            }
        return s;
    }
};