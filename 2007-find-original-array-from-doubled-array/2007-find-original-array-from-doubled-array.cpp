class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        queue<int>q;
        vector<int>res,empty;
        int n=changed.size();
        if(n%2) return empty;
        for(int i=0;i<n;i++){
            if(q.empty()) q.push(changed[i]);
            else{
                if(q.front()*2==changed[i]) 
                    res.push_back(q.front()),q.pop();
                else q.push(changed[i]);
            }
        }
        if(q.size()) return empty;
        return res;
    }
};