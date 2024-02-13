class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(string& w:words){
            if(check(w)) {
                    ans=w;
                    break;
            }
        }
        return ans;
    }
    bool check(string& s){
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
};