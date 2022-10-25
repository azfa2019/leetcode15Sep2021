class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int p1=0,p2=0,i=0,j=0;
        while(p1<w1.size()&&p2<w2.size()){
            if(w1[p1][i]!=w2[p2][j]) return false;
            i++;
            if(i==w1[p1].size()) i=0,p1++;
            j++;
            if(j==w2[p2].size()) j=0,p2++;
        }
        return p1==w1.size()&&p2==w2.size();
    }
};