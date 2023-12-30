class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        vector<int> hash(26);
        for(auto& w:words)
            for(auto&c:w){
                hash[c-'a']++;
            }
        for(int i:hash) if(i%n) return false;
        return true;
    }
};