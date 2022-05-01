class Solution {
public:
    bool backspaceCompare(string s, string t) {
        extract(s),extract(t);
        return s==t;
    }
    void extract(string& s){
        int slow=0;
        for(auto c:s){
            if(c=='#') {
                if(slow>0) slow--;
            }else s[slow++]=c;
        }
        s.resize(slow);
    }
};