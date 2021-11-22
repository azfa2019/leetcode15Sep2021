class Solution {
  public:
  bool isPalindrome(string s) {
    int n=s.size();
    int left=0,right=n-1;
    while(left<right){
      while(left<right && isalnum(s[left])==false) left++;
      while(left<right && isalnum(s[right])==false) right--;
      char l=toupper(s[left]);
      char r=toupper(s[right]);
      if(l!=r) return false;
      else left++,right--;
    }
    return true;
  }
};