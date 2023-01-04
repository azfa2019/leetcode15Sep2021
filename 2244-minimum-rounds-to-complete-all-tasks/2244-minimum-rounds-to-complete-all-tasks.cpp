class Solution {
public:
    int check(int x){
        if(x==1) return -1;
        if(x%3==0) return x/3;
        return x/3+1;
    }
    int minimumRounds(vector<int>& ta) {
        sort(ta.begin(),ta.end());
        ta.push_back(0);
        vector<int>num;
        int n=ta.size();
        int cnt=0;
        for(int i=0;i<n;i++)
            if(!i||ta[i]!=ta[i-1]) num.push_back(cnt),cnt=1;
            else cnt++;
        int res=0;
        for(int x:num) {
            int t=check(x);
            if(t<0) return -1;
            res+=t;
        }
        return res;
    }
};