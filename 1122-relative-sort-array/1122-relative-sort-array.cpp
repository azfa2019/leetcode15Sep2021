class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>hash;
        for(int i=0;i<arr2.size();i++) hash[arr2[i]]=i-arr2.size();
        sort(arr1.begin(),arr1.end(),[&](int a,int b){
            if(hash[a]==hash[b]) return a<b;
            return hash[a]<hash[b];
        });
        return arr1;
    }
};