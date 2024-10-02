class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& _arr) {
        if(_arr.size()==0) return {};
        auto arr=_arr;
        sort(arr.begin(),arr.end());
        int r=1;
        unordered_map<int,int>hash;
        hash[arr[0]]=r;
        for(int i=1;i<arr.size();i++){
            while(i<arr.size()&&arr[i]==arr[i-1]) i++;
            if (i<arr.size())hash[arr[i]]=++r;
        }
        for(int i=0;i<arr.size();i++) _arr[i]=hash[_arr[i]];
        return _arr;
    }
};