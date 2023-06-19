class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0;
        int alt=0;
        for(int a:gain) alt+=a, res=max(res,alt);
        return res;
    }
};