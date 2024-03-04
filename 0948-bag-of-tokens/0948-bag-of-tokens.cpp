class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int l=0;
        while(l<n && power>=tokens[l]) power-=tokens[l++];
        int res=l;
        for(int r=n-1;r>l;r--){
            if(l<n-r) break;
            power+=tokens[r];
            while(l<r && power>=tokens[l]) power-=tokens[l++];
            res=max(res,l-(n-r));
        }
        return res;
    }
};