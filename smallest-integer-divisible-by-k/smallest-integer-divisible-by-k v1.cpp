class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int count=0;
        int num=1;
        unordered_set<int>st;
        while(true){
            count++;
            int r=num%k;
            if(r==0) return count;
            if(st.find(r)!=st.end()) return -1;
            st.insert(r);
            num=r*10+1;
        }
        return -1;
    }
};
// n1 = a*K+r1
// n2 = 10*n1+1 = 10a*K+10r1+1, r2=10*r1+1
// n3 = 10*n2+1 = 10*r2+1
