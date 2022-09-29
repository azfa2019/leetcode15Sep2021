class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>heap;
        for(auto v:arr){
            heap.push({abs(v-x),v});
            if(heap.size()>k) heap.pop();
        }
        vector<int>res;
        while(heap.size()) res.push_back(heap.top().second),heap.pop();
        sort(res.begin(),res.end());
        return res;
    }
};