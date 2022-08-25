class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>hash;
        for(auto c:magazine) hash[c]++;
        for(auto c:ransomNote){
            if(!hash.count(c)) return false;
            hash[c]--;
            if(hash[c]<0) return false;
        }
        return true;
    }
};