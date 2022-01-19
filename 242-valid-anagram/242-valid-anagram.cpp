class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>mp(26);
        for(char c:s) mp[c-'a']++;
        for(char c:t) mp[c-'a']--;
        for(auto item:mp) {
            if(item!=0) return false;
        }
        return true;
    }
};