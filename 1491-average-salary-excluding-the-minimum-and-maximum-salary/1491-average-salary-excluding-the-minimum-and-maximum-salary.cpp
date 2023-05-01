class Solution {
public:
    double average(vector<int>& salary) {
        int mn=1e7,mx=0;
        int sum=0,cnt=-2;
        for(int& s:salary){
            mn=min(mn,s);
            mx=max(mx,s);
            sum+=s;
            cnt++;
        }
        return (double)(sum-mn-mx)/cnt;
    }
};