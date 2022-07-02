const int mod=1e9+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int maxh=max(hc[0],h-hc[hc.size()-1]);
        int maxw=max(vc[0],w-vc[vc.size()-1]);
        for(int i=1;i<hc.size();i++)
            maxh=max(maxh,hc[i]-hc[i-1]);
        for(int i=1;i<vc.size();i++)
            maxw=max(maxw,vc[i]-vc[i-1]);
                //return int64_t(maxh)*int64_t(maxh)%1000000007;

        return int64_t(maxh)*int64_t(maxw)%mod;
    }
};