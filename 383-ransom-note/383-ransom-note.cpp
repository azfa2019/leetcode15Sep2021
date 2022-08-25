class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>hash;
        for(auto c:magazine) hash[c]++;
        for(auto c:ransomNote){
            if(!hash[c]) return false;
            else hash[c]--;
        }
        return true;
    }
};