class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        typedef long long LL;
        int n=nums.size();
        int res=0;
        vector<unordered_map<LL,int>> f(n);
        for(int i=0;i<n;i++){
            for(int k=0;k<i;k++){
                LL j=(LL)nums[i]-nums[k];
                auto it=f[k].find(j);
                int t=0;
                if(it!=f[i].end()) t=it->second,res+=t;
                f[i][j]+=t+1;
        }
        }
       return res;
    }
};