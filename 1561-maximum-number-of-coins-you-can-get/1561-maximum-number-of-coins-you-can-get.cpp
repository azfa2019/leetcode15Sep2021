class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int n=piles.size(),res=0;
        for(int i=0,j=1;i<n/3;i++){
            res+=piles[j];
            j+=2;
        }
        return res;
    }
};