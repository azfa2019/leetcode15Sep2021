class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int res=m-p[0]-p[1];
        if(res>=0) return res;
        return m;
        
    }
};