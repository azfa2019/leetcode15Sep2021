class Solution {
public:
    int minDeletions(string s) {
        set<int>st;
        int a[26]={0};
        //cout<<a[0]<<a[25]<<endl;
        for(char c:s) a[c-'a']++;
        int cnt=0;
        for(int i=0;i<26;i++){
            if(!st.count(a[i])){
                st.insert(a[i]);
                continue;
            }
            while(st.count(a[i])&& a[i]!=0) a[i]--,cnt++;
            st.insert(a[i]);
        }
        return cnt;
    }
};