class Solution {
    int n;
    string s;
public:
    int countSubstrings(string s) {
        this->s=s;
        this->n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=expand(i,i);
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                count+=expand(i,i+1)-1;
            }
        }
        return count;
    }
    int expand(int i,int j){
        while(i>=0 && j<n && s[i]==s[j]) i--,j++;
        return (j-i+1)/2;
    }
};
// cbabd
// 01234
// c dbbd a
// 0 1234 5