class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        int hash[26];
        memset(hash,0,sizeof hash);
        for(auto& w:words)
            for(auto&c:w){
                hash[c-'a']++;
            }
        for(int i:hash) if(i%n) return false;
        return true;
    }
};