class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return false;
        vector<int>hash(26,0);
        for(char c:s1) hash[c-'a']++;
        vector<int>hash2(26,0);
        for(int i=0;i<s2.size();i++){
            hash2[s2[i]-'a']++;
            if(i-n1>=0) {
                hash2[s2[i-n1]-'a']--;
            }
            if(hash2==hash) return true;
        }
        return false;
    }
};

// xxx x
// 012 3