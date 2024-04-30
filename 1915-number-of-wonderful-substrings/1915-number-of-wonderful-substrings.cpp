class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int cnt[1024]={0};
        cnt[0]=1;
        long ans=0L;
        int sum=0;
        for(char&c:word){
            sum^=1<<(c-'a');
            ans+=cnt[sum];
            for(int j=1;j<1024;j<<=1)
                ans+=cnt[sum^j];
            cnt[sum]++;
        }
        return ans;
    }
};