class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        unordered_map<string,int>hash;
        int res=0;
        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+=to_string(g[i][j]);
                s+=",";
            }
            s.pop_back();
            hash[s]++;
        }
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<m;j++){
                s+=to_string(g[j][i]);
                s+=",";
            }
            s.pop_back();
            if(hash.count(s)) res+=hash[s];
        }
        return res;
    }
};