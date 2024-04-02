class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return check(s,t) && check(t,s);
    }
    bool check(string s,string t){
        unordered_map<char,char>hash;
        int n=s.size();
        for(int i=0;i<n;i++){
        if(hash.count(s[i])) {
            if(hash[s[i]]!=t[i]) return false;
        } else
            hash[s[i]]=t[i];
        }
        return true;
    }
};