class Solution {
public:
    int maximumNumberOfOnes(int w, int h, int s, int m) {
        vector<vector<int>>sq(s,vector<int>(s));
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                sq[i%s][j%s]++;
        priority_queue<int> heap;
        for(int i=0;i<s;i++)
            for(int j=0;j<s;j++)
                heap.push(sq[i][j]);
        int res=0;
        for(int i=0;i<m;i++) res+=heap.top(),heap.pop();
        return res;
    }
};