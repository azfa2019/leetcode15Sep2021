class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>f(26);
        for(char c:t) f[c-'a']++;
        for(char c:s) f[c-'a']--;
        for(int i=0;i<26;i++) if(f[i]) return i+'a';
        return 'a';
    }
};