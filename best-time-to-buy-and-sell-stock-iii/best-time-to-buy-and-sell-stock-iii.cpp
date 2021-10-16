class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    //states: hold 1, sold 1, hold 2, sold 2
    int hold1=INT_MIN,sold1=0,hold2=INT_MIN,sold2=0;
    for(int i=0;i<prices.size();i++){
      int hold1Tmp=hold1;
      int sold1Tmp=sold1;
      int hold2Tmp=hold2;
      int sold2Tmp=sold2;
      hold1=max(hold1Tmp,-prices[i]);
      sold1=max(sold1Tmp,hold1Tmp+prices[i]);
      hold2=max(hold2Tmp,sold1Tmp-prices[i]);
      sold2=max(sold2Tmp,hold2Tmp+prices[i]);
    }
    return max(hold2,sold2);
  }
};