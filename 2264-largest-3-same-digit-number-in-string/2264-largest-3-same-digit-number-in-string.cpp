class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        char c='.';
        for(int i=2;i<n;i++){
            if(num[i]==num[i-1] && num[i-1]==num[i-2]) {
                if(c<num[i]) c=num[i];
            }
        }
        string res="";
        if (c!='.') res=res+c+c+c;
        return res;
    }
};