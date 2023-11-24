class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int n=piles.size(),res=0;
        for(int i=0;i<n/3;i++){
            res+=piles[i*2+1];
        }
        return res;
    }
};