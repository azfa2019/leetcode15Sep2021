class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]==s[r]) l++,r--;
            else break;
        }
        
        if(!check(s,l,r-1) && !check(s,l+1,r)) return false;
        
        return true;
    }
    bool check(string &s,int l,int r){
        while(l<r) {
            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;
    }
};
