class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        sort(t.begin(),t.end()), sort(a.begin(),a.end());
        int n=t.size();
        for(int i=0;i<n;i++) 
            if(t[i]!=a[i]) return false;
        return true;
    }
};