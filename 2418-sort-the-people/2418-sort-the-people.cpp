class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string>hash;
        int n=names.size();
            for(int i=0;i<n;i++) 
                hash[heights[i]]=names[i];
        sort(heights.rbegin(),heights.rend());
        vector<string>ans;
        for(auto& h:heights) ans.push_back(hash[h]);
        return ans;
    }
};