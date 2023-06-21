typedef pair<long long,long long> PII;
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<PII> a;
        for(int i=0;i<nums.size();i++) a.push_back({nums[i],cost[i]});
        sort(a.begin(),a.end());
        long long sumCost=0;
        for(int i=0;i<n;i++) sumCost+=cost[i];
        long long ans=0,s=0,mid=(sumCost+1)/2;
        for(auto& [x1,c1]:a){
            s+=c1;
            if(s>=mid) {
                for(auto&[x2,c2]:a) ans+=(long long)abs(x2-x1)*c2;
                break;
            }
        }
        return ans;
    }
};