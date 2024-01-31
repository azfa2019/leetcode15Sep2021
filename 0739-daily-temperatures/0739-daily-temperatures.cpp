class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>stk;
        vector<int>res(t.size());
        for(int i=t.size()-1;i>=0;i--){
            while(stk.size() && t[i]>=t[stk.top()]) stk.pop();
            if(stk.size()) res[i]=stk.top()-i;
            stk.push(i);
        }
        return res;
    }
};