class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
        string res="";
        for(char &c:s){
            if(c=='(') cnt++,res+=c;
            else if(c==')'){
                if(cnt) cnt--,res+=c;
            }else res+=c;
        }
        reverse(res.begin(),res.end());
        s=res,res="",cnt=0;
        for(char &c:s){
            if(c==')') cnt++,res+=c;
            else if(c=='('){
                if(cnt) cnt--,res+=c;
            }else res+=c;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};