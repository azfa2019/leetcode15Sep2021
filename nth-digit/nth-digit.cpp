class Solution {
  public:
  int findNthDigit(int n) {
    int nCopy=n;
    int d=1;
    while(n>calcDigits(d)) {
      n-=calcDigits(d);
      d++;
    }
    //cout<<"n="<<n<<endl;
    //cout<<d<<endl; //d: the target number will have d digits
    int target=pow(10,d-1)+n/d-1;
    int digit=n%d;
    if(digit==0) 
      return to_string(target)[d-1]-'0';
    else
      return to_string(target+1)[digit-1]-'0';
  }
  long calcDigits(int d){
    long start=pow(10,(d-1));
    long end=pow(10,d)-1;
    return (end-start+1)*d;
  }
};