class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>hash;
        for(char& c:s) hash[c]++;
        int ans=0,odd=0;
        for(auto &[k,v]:hash) {
            if(v) ans+=v/2*2;
            if(v%2) odd=1;
        }
        return ans+odd;
    }
};