class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        long long f[n+1];
        f[n]=0;
        for(int i=n-1;i>=0;i--){
            auto& q=questions[i];
            int j=q[1]+i+1;
            f[i]=max(f[i+1],q[0]+(j<n?f[j]:0));
        }
        return f[0];
    }
};