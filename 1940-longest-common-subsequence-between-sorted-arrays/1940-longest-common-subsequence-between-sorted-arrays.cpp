class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int>hash(101);
        for(auto &a:arrays)
            for(auto &x:a)
                hash[x]++;
        vector<int>res;
        for(int i=1;i<=100;i++)
            if(hash[i]==arrays.size()) res.push_back(i);
        return res;
    }
};