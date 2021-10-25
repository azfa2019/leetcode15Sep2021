class Solution {
  public:
  int numberOfDays(int year, int month) {
    unordered_map<int,int>map0{{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    if(month==2){
      if(year%100==0){
        if(year%400==0) return 29;
        else return 28;
      } else if(year%4==0) return 29;
      else return 28;
    }
    return map0[month];
  }
};