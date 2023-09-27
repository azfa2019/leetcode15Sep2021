class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n=0;
        for(char& c:s) {
            if(isdigit(c)) n*=c-'0';
            else n++;
        }
        for(int i=s.size()-1;i>=0;i--){
            char c=s[i];
            if(isdigit(c)){
                int x=c-'0';
                n/=x;
                k%=n;
                if(!k) k=n;
            }else{
                if(k==n) return string(1,c);
                n--;
            }
        }
        return "";
    }
};