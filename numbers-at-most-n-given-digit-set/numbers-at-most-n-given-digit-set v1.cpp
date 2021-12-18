class Solution {
    int count;
    int nDigit;
    int k;
    string num;
    public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        this->nDigit=digits.size();
        this->num=to_string(n);
        this->k=num.size();
        for(int i=1;i<=k-1;i++)
            count+=pow(nDigit,i);
        dfs(0,digits);
        return count;

    }
    void dfs(int pos,vector<string>& digits){
        if(pos==k) {
            count++;
            return;
        }
        for(string d:digits){
            if(stoi(d)+'0'<num[pos]) count+=pow(nDigit,k-1-pos);
            else if(stoi(d)+'0'==num[pos]) dfs(pos+1,digits);
        }
    }
};
