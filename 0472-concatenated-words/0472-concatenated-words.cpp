class Solution {
public:
    typedef unsigned long long ULL;
    static const int N=1010,P=131;
    vector<vector<ULL>>hs;
    ULL p[N];
    vector<string>words;
    unordered_set<ULL>hash;
    ULL get(vector<ULL>&h,int l,int r){
        return h[r]-h[l-1]*p[r-l+1];
    }
    bool check(int k){
        string word=words[k];
        int n=word.size();
        vector<int>f(n+1,INT_MIN);
        f[0]=0;
        for(int i=0;i<n;i++){
            if(f[i]<0) continue;
            for(int j=n-i;j;j--){
                if(hash.count(get(hs[k],i+1,i+j))){
                    f[i+j]=max(f[i+j],f[i]+1);
                    if(f[n]>1) return true;
                }
            }
        }
        return false;
    }
    vector<string>findAllConcatenatedWordsInADict(vector<string>& _words) {
        p[0]=1;
        for(int i=1;i<N;i++) p[i]=p[i-1]*P;;
        words=_words;
        int n=words.size();
        hs.resize(n);
        for(int i=0;i<n;i++){
            hs[i].resize(words[i].size()+10);
            for(int j=1;j<=words[i].size();j++) hs[i][j]=hs[i][j-1]*P+words[i][j-1];
            hash.insert(hs[i][words[i].size()]);
        }
        vector<string>res;
        for(int i=0;i<n;i++) 
            if(check(i)) res.push_back(words[i]);
        return res;
    }
};