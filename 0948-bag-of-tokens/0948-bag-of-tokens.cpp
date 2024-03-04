class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int l=0,r=n-1;
        int res=0,score=0;
        while(l<=r){
            if(power<tokens[l]){
                if(score<=0) return res;
                power+=tokens[r];
                score--,r--;
            }else{
                power-=tokens[l];
                score++,l++;
                res=max(res,score);
            }
        }
        return res;
    }
};