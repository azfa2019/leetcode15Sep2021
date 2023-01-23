class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>hash1(n+1),hash2(n+1);
        
        for(auto& p:trust) hash1[p[0]]++,hash2[p[1]]++;
        for(int i=1;i<=n;i++) if(hash1[i]==0&&hash2[i]==n-1) return i;
        return -1;
    }
};