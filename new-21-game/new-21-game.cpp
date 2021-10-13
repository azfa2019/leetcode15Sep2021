class Solution {
public:
    double new21Game(int N, int K, int W) {
        double dp[K+W];
        double s=0;
        for(int i = K; i<K+W; ++i)
        {
            dp[i] = i<=N? 1:0;
            s+=dp[i];
        }
        for(int i = K-1; i>=0; --i)
        {
            dp[i] = s/W;
            s = s-dp[i+W]+dp[i];
        }
        return dp[0];

    }
};