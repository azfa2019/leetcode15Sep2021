class Solution {
public:
    string convertToTitle(int c) {
        string res="";
        while(c){
            c--;
            res+=c%26+'A';
            c/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};