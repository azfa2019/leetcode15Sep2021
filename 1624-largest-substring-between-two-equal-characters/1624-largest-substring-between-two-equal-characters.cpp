class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res=-1e9;
        for(int i=0;i<26;i++){
            char c='a'+i;
            //cout<<c<<endl;
            res=max(res,dist(c,s));
    }
        return res<0?-1:res;
    }
    int dist(char c,string s){
        int n=s.size();
        int l=1e9,r=-1;
        for(int i=0;i<n;i++){
            if(s[i]==c) 
                l=min(l,i),r=max(r,i);
        }
        return r-1-l;
    }
};