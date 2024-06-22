class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        unordered_set<char>win;
        int l=0,r=0,res=0;
        while(r<s.size()){
            while(win.count(s[r])){
                win.erase(s[l++]);
            }
            win.insert(s[r]);
            res+=r-l+1;
            r++;
        }
        return res;
    }
};