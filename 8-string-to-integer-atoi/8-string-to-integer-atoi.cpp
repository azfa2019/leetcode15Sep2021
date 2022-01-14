class Solution {
    public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        string t="";
        while(i<n&& s[i]==' '){
            i++;
        }
        t=s.substr(i);
        if(t.size()==0) return 0;
        bool neg=false;
        if(t[0]=='+') t=t.substr(1);
        else if(t[0]=='-') neg=true,t=t.substr(1);
        if(!isdigit(t[0])) return 0;

        long ans=0;
        for(char c:t){
            if(c>='0' && c<='9'){
                if(neg){
                    ans=ans*10-(c-'0');
                    if(ans<=INT_MIN) return INT_MIN;
                }else{
                    ans=ans*10+(c-'0');
                    if(ans>=INT_MAX) return INT_MAX;
                }
            }else break;
        }
        return ans;
    }
};