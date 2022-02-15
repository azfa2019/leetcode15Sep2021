class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n=s.size();
        vector<int>hash(26,0);
        if(k>n) return 0;
        for(int i=0;i<k;i++) hash[s[i]-'a']++;
        int res=0;
        if(check(hash)) res++;
        for(int i=k;i<n;i++){
            hash[s[i]-'a']++;
            hash[s[i-k]-'a']--;
            if(check(hash)) res++;
        }
        return res;
    }
    bool check(vector<int>&hash){
        for(int i=0;i<26;i++) if(hash[i]>1) return false;
        return true;
    }
};