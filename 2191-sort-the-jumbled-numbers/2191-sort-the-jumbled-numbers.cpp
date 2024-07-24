class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>vec;
        for(int k=0;k<n;k++){
            int cur=0,num=nums[k];
            string s=to_string(num);
            for(int i=0;i<s.size();i++) {
                cur=cur*10+mapping[s[i]-'0'];
            }
            vec.push_back({cur,k});
        }
        sort(vec.begin(),vec.end());
        vector<int>res;
        for(auto& e:vec) res.push_back(nums[e[1]]);
        return res;
    }
};