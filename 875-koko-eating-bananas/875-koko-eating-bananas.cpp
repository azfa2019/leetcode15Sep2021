class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+r>>1;
            if(check(mid,piles)>h) l=mid+1;
            else r=mid;
        }
        return l;
    }
    int check(int x,vector<int>&piles){
        int count=0;
        for(int p:piles){
            count+=p/x;
            count+=(p%x?1:0);
        }
        return count;
    }
};