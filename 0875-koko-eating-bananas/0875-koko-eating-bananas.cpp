class Solution {
public:
    vector<int> piles;
    int h;
    bool check(int x){
        int res=0;
        for(auto p:piles){
            res+=(p+x-1)/x;
        }
        return res<=h;
    }
    int minEatingSpeed(vector<int>& _piles, int _h) {
        h=_h;
        piles=_piles;
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};