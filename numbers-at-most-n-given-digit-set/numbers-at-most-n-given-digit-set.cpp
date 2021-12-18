class Solution {
    int count;
    int numDigits;
    string nStr;
    int digitN;
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        this->numDigits=digits.size();
        this->nStr=to_string(n);
        this->digitN=nStr.size();
        for(int i=1;i<=digitN-1;i++) count+=pow(numDigits,i);
        dfs(0,digits);
        return count;
    }
    void dfs(int pos,vector<string>& digits){
        if(pos==digitN) {
            count++;
            return;
        }
        for(string d:digits){
            if('0'+stoi(d)<nStr[pos]) count+=pow(numDigits,digitN-pos-1);
            else if('0'+stoi(d)==nStr[pos]) dfs(pos+1,digits);
        }
    }
};