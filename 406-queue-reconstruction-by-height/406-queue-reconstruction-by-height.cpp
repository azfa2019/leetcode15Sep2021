class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp=[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        };
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>res;
        for(auto p:people){
            res.insert(res.begin()+p[1],p);
        }
        return res;
    }
};