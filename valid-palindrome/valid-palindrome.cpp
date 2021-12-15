class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            while(l<r && !isalnum(s[l])) l++;
            while(l<r && !isalnum(s[r])) r--;
            char lc=toupper(s[l]);
            char rc=toupper(s[r]);
            if(lc!=rc) return false;
            l++,r--;
        }
        return true;
    }
};