class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>heap;
        unordered_map<int,int>hash;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++) cnt+=mat[i][j];
            heap.push({cnt,i});
        }
        vector<int>res;
        while(k--) res.push_back(heap.top().second),heap.pop();
        return res;
    }
};