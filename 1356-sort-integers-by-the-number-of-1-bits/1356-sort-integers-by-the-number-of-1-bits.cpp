class Solution {
public:
    static int cnt(int x){
        int cnt=0;
        while(x) cnt++,x-=(x&-x);
        return cnt;
    }
    static bool cmp(int x,int y){
        int c1=cnt(x),c2=cnt(y);
        if(c1!=c2) return c1<c2;
        return x<y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};