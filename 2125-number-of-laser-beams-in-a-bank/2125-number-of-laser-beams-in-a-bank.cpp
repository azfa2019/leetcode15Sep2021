class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<bool>laser(n);
        vector<int>cnt(n);
        for(int i=0;i<n;i++) cnt[i]=count(bank[i]);
        int res=0;
        int last=cnt[0];
        for(int i=1;i<n;i++){
            if(!cnt[i]) continue;
            res+=cnt[i]*last;
            last=cnt[i];
        }
        return res;
    }
    int count(string& s){
        int res=0;
        for(auto& c:s) if(c=='1') res++;
        return res;
    }
};