class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int>S;
        for(auto num:nums1)
            S.insert(num);
        vector<int>res;
        for(auto num:nums2){
            if(S.count(num)){
                res.push_back(num);
                S.erase(S.find(num));
            }
        }
        return res;
    }
};
//4 5 9
//4 4 8 9 9 