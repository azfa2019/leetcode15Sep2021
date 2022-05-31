class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        int cur=0;
        unordered_set<int>st;
        for(int i=0;i<k-1;i++) cur=cur*2+(s[i]=='1');;
        for(int i=k-1;i<s.size();i++){
            cur=cur*2+(s[i]=='1');
            st.insert(cur);
            cur&=~(1<<(k-1));
        }
        return st.size()==(1<<k);
    }
};