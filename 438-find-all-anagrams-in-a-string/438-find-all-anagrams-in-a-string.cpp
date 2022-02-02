class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>smap(255,0);
        vector<int>pmap(255,0);
        vector<int>ans;
        for(char c:p) pmap[c]++;
        int m=p.size(),n=s.size();
        for (int i=0;i<n;i++){
            char c=s[i];
            smap[c]++;
            if(i+1>m) {
                char l=s[i-m];
                smap[l]--;
            }
            if(smap==pmap) ans.push_back(i-m+1);
        }
        return ans;
    }
};