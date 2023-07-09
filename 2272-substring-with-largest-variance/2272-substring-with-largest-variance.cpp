class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        for(char a='a';a<='z';a++)
            for(char b='a';b<='z';b++){
                if(a==b) continue;
                int diff=0,diffwb=-s.size();
                for(char c:s){
                    if(c==a) diff++,diffwb++;
                    else if(c==b){
                        diffwb=--diff;
                        diff=max(diff,0);
                    }
                    ans=max(ans,diffwb);
                }
            }
        return ans;
    }
};