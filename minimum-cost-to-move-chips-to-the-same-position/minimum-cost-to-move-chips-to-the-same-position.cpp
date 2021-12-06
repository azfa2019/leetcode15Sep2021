class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even=0,odd=0;
        for(int num:position){
            if(num%2==1) odd++;
            else even++;
        }
        return min(even,odd);
    }
};
// 2 2 2 3 3 5