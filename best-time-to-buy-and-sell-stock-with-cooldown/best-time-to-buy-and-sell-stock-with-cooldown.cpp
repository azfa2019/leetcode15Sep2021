class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
      //states: hold, sold, cooled (after sold)
      int n=prices.size();
      int hold=-prices[0], sold=0, cooled=0;
      
      for(int i=1;i<n;i++){
        int hold2=hold,cooled2=cooled,sold2=sold;
        hold=max(hold2,cooled2-prices[i]);
        cooled=max(sold2,cooled2);
        sold=hold2+prices[i];
      }
      return max(sold,cooled);
    }
};