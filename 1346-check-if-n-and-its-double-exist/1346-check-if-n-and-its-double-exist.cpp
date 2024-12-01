class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>hash;
        for(int a:arr) hash[a]++;
        for(int a:arr) {
            if(a==0){
                if(hash[a]>=2) return true;
            }else{
                if(hash.count(2*a)) return true;
            }
        }
        return false;
    }
};