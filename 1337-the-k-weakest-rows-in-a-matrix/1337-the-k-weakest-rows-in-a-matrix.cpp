class Solution {
    struct compare{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            if(a.first==b.first) return a.second>b.second;
            else return a.first>b.first;
        }
    };
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(int i=0;i<mat.size();i++){
            auto row=mat[i];
            int s=power(row,row.size());
            //int s=accumulate(row.begin(),row.end(),0);
            pq.push({s,i});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            int idx=pq.top().second;
            pq.pop();
            ans.push_back(idx);
        }
        return ans;
    }
    int power(vector<int>&row,int n){
        int l=0,r=n-1;
        while(l<r){
            int m=l+r>>1;
            if(row[m]==1) l=m+1;
            else r=m;
        }
        return row[l]==0?l:n;
    }
};