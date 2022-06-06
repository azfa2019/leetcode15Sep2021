class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>din(n+1),dout(n+1);
        for(auto t:trust){
            din[t[1]]++,dout[t[0]]++;
        }
        for(int i=1;i<=n;i++) 
            if(din[i]==n-1 && dout[i]==0) return i;
        return -1;
    }
};