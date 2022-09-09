class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        stack<int>stk;
        int res=0;
        for(auto e:p){
            while(stk.size()&&stk.top()<e[1]) res++,stk.pop();
            stk.push(e[1]);
        }
        return res;
    }
};