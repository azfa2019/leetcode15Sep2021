class Solution {
public:
    bool check(string& a,string& b){
        if(a.size()+1!=b.size()) return false;
        int i=0;
        for(auto c:b){
            if(i<a.size() && a[i]==c) i++;
        }
        return i==a.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>f(n);
        sort(words.begin(),words.end(),[](string& a,string& b){
            return a.size()<b.size();
        });
        int res=0;
        for(int i=0;i<n;i++){
            f[i]=1;
            for(int j=0;j<i;j++){
                if(check(words[j],words[i])) f[i]=max(f[i],f[j]+1);
            }
            res=max(res,f[i]);
        }
        return res;
    }
};