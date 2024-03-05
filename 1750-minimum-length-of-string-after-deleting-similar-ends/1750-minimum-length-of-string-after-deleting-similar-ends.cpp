class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]==s[r]){
                auto c=s[l];
                while(l<=r && s[l]==c) l++;
                while(l<=r && s[r]==c) r--;
            }else break;
        }
        return r-l+1;
    }
    
};