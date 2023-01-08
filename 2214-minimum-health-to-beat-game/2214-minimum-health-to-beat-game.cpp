typedef long long LL;
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        LL sum=0;
        for(auto& d:damage) sum+=d;
        LL maxv=*max_element(damage.begin(),damage.end());
        if(armor>=maxv) {
            LL res=sum-maxv+1;
            return res;
        }
        return (LL)sum-armor+1;
    }
};