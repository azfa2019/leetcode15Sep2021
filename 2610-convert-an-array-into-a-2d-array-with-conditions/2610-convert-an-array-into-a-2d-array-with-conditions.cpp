class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>hash;
        int mx=0;
        for(int num:nums) hash[num]++,mx=max(mx,hash[num]);
        vector<vector<int>>res(mx);
        for(auto e:hash){
            int n=e.second,num=e.first;
            for(int i=0;i<n;i++)
                res[i].push_back(num);
        }
        return res;
    }
};