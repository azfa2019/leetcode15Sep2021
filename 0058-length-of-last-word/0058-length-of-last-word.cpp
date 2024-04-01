class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ') continue;
            int j=i;
            while(j>=0 && s[j]!=' ') j--;
            return i-j;
        }
        return 0;
    }
};