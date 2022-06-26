class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int w=n-k;
        int sum=accumulate(card.begin(),card.begin()+w,0);
        int res=sum;
        for(int i=w;i<n;i++){
            sum+=card[i]-card[i-w];
            res=min(res,sum);
        }
        return accumulate(card.begin(),card.end(),0)-res;
    }
};