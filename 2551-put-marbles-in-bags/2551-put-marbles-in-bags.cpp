class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n=w.size();
        for(int i=0;i<n-1;i++) w[i]+=w[i+1];
        sort(w.begin(),w.end()-1);
        long ans=0;
        for(int i=0;i<k-1;i++)
            ans+=w[n-2-i]-w[i];
        return ans;
    }
};