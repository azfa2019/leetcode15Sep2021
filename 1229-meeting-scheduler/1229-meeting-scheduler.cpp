class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& s1, vector<vector<int>>& s2, int d) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int i=0,j=0;
        int m=s1.size(),n=s2.size();
        while(i<m&&j<n){
            int st=max(s1[i][0],s2[j][0]);
            int ed=min(s1[i][1],s2[j][1]);
            if(st+d<=ed) return {st,st+d};
            else if(s1[i][1]<s2[j][1]) i++;
            else j++;
        }
        return {};
    }
};

// 10-- 50.  60--- 120 140---210
//0---15     60--70 

// 10 ---- 90
//5---15 17----100