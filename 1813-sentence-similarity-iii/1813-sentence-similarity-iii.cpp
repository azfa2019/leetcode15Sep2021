class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()>s2.size()) return areSentencesSimilar(s2,s1);
        vector<string> arr1=split(s1),arr2=split(s2);
        int n=arr1.size(),m=arr2.size(),l=0,r=0;
        while(l<n&&arr1[l]==arr2[l]) l++;
        while(r<n-l && arr1[n-r-1]==arr2[m-r-1]) r++;
        return l+r==n;
    }
    vector<string>split(string s){
        vector<string>ans;
        stringstream ss;
        ss<<s;
        while(ss>>s) ans.push_back(s);
        return ans;
    }
};