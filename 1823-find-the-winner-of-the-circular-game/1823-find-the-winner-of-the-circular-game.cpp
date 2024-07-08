class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n<=1) return n;
        int ans=(findTheWinner(n-1,k)+k)%n;
        return ans==0?n:ans;
    }
};