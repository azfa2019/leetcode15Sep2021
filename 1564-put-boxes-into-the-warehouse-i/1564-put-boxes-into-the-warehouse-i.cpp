class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& b, vector<int>& w) {
        int minH=w[0];
        for(int i=1;i<w.size();i++) minH=min(minH,w[i]),w[i]=minH;
        sort(b.rbegin(),b.rend());
        int i=b.size()-1,j=w.size()-1;
        int res=0;
        while(i>=0&&j>=0){
            if(b[i]<=w[j]) res++,i--,j--;
            else j--;
        }
        return res;
    }
};