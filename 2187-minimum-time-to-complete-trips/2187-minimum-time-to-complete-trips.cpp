typedef unsigned long long ULL;
class Solution {
public:
    vector<int> time;
    int t;
    bool check(ULL x){
        ULL res=0;
        for(auto t:time)
            res+=x/t;
        return res>=t;
    }
    long long minimumTime(vector<int>& _time, int _t) {
        time=_time;
        t=_t;
        int n=time.size();
        ULL l=0,r=2e16;
        while(l<r){
            ULL mid=l+(r-l)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};