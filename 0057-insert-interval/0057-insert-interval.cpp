class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int n=a.size();
        int k=0;
        vector<vector<int>>res;
        while(k<n && a[k][1]<b[0]) res.push_back(a[k++]);
        
        if(k<n){
            b[0]=min(a[k][0],b[0]);
            while(k<n && a[k][0]<=b[1]) b[1]=max(b[1],a[k++][1]);
        }
        res.push_back(b);
        while(k<n) res.push_back(a[k++]);
        return res;
    }
};