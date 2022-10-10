class Solution {
public:
    string breakPalindrome(string str) {
        if(str.size()==1) return "";
        for(int i=0;i<str.size();i++){
            if(str[i]!='a'&& (str.size()%2==0 ||i!=str.size()/2)) {
                str[i]='a';
                return str;
            }
        }
        str.back()='b';
        return str;
    }
};