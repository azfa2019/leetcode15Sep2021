class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int>f(k+1);
        int sum=0;
        for(auto& pile:piles){
            int n=pile.size();
            for(int i=1;i<n;i++) pile[i]+=pile[i-1];
            sum=min(sum+n,k);
            for(int j=sum;j>=0;j--)
                for(int w=0;w<min(n,j);w++)
                    f[j]=max(f[j],f[j-w-1]+pile[w]);
        }
        return f[k];
    }
};