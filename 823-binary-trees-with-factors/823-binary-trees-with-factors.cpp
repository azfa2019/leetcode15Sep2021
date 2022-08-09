class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>hash;
        for(int i=0;i<arr.size();i++) hash[arr[i]]=i;
        vector<int>f(n);
        int res=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            f[i]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int d=arr[i]/arr[j];
                    if(hash.count(d)) {
                        int k=hash[d];
                        f[i]=(f[i]+(long long)f[j]*f[k])%mod;
                    }
                }
            }
            res=(res+f[i])%mod;
        }
        return res;
    }
};