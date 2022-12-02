class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26), cnt2(26);
        for(char c:word1) cnt1[c-'a']++;
        for(char c:word2) cnt2[c-'a']++;
        unordered_set<int>hash1,hash2;
        for(int i=0;i<26;i++) if(cnt1[i]>0) hash1.insert(i);
        for(int i=0;i<26;i++) if(cnt2[i]>0) hash2.insert(i);
        if(hash1!=hash2) return false;
        sort(cnt1.begin(),cnt1.end());
        sort(cnt2.begin(),cnt2.end());
        for(int i=0;i<26;i++) 
            if(cnt1[i]!=cnt2[i]) return false;
        return true;
    }
};