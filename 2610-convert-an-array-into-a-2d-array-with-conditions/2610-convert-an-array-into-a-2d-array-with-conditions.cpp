class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int n=nums.size();
        int cnt[201]={0};
        for(int num:nums) cnt[num]++;
        vector<vector<int>>res;
        while(n){
            vector<int>v;
            for(int i=1;i<=200;i++){
                if(cnt[i]){
                    v.push_back(i);
                    cnt[i]--,n--;
                }
            }
            res.push_back(v);
        }
        return res;
    }
};