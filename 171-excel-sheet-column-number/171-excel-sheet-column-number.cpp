class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int res=0;
        while(columnTitle!=""){
            res=res*26+(columnTitle[0]-'A'+1);
            columnTitle=columnTitle.substr(1);
        }
        return res;
    }
};