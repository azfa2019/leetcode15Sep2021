class Solution {
public:
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    string gcdOfStrings(string a, string b) {
        if(a+b!=b+a) return "";
        return a.substr(0,gcd(a.size(),b.size()));
    }
};