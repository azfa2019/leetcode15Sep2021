class Solution {
public:
    int compareVersion(string v1, string v2) {
        for(int i=0,j=0;i<v1.size() || j<v2.size();){
            int a=i,b=j;
            while(a<v1.size() && v1[a]!='.') a++;
            while(b<v2.size() && v2[b]!='.') b++;
            int x1=a==i?0:stoi(v1.substr(i,a-i));
            int x2=b==j?0:stoi(v2.substr(j,b-j));
            if(x1<x2) return -1;
            if(x1>x2) return 1;
            i=a+1,j=b+1;
         }
        return 0;
    }
};