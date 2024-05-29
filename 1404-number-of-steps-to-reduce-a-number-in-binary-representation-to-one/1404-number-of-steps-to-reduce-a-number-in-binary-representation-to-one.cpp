class Solution {
public:
    int numSteps(string s) {
        int res=0;
        bool c=0;
        for(int i=s.size()-1;i>0;i--){
            if(c){
                if(s[i]=='0')res+=2,c=1;
                else res++,c=1;
            }else{
                if(s[i]=='0') res++,c=0;
                else res+=2,c=1;
            }
        }
        if(c) res++;
        return res;
    }
};