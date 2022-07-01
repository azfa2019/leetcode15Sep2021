class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int c0=0,c2=0,c1=0;
        for(auto c:costs){
            int c0b=c0,c1b=c1,c2b=c2;
            c0=min(c2b,c1b)+c[0];
            c1=min(c0b,c2b)+c[1];
            c2=min(c0b,c1b)+c[2];
        }
        return min(c0,min(c1,c2));
    }
};