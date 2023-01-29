class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int res=0;
        for(int p:piles) res^=p;
        if(res) return true;
        return false;
    }
};