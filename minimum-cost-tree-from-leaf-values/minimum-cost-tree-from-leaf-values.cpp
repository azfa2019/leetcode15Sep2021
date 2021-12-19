class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<int>prevBig(n,INT_MAX);
        vector<int>nextBig(n,INT_MAX);
        stack<int>stck;
        for(int i=0;i<n;i++){
            while(!stck.empty() &&arr[stck.top()]<=arr[i]){
                nextBig[stck.top()]=arr[i];
                stck.pop();
            }
            stck.push(i);
        }
        while(!stck.empty()) stck.pop();
        for(int i=n-1;i>=0;i--){
            while(!stck.empty() && arr[stck.top()]<arr[i]){
                prevBig[stck.top()]=arr[i];
                stck.pop();
            }
            stck.push(i);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int tmp=min(prevBig[i],nextBig[i]);
            if(tmp!=INT_MAX) sum+=arr[i]*tmp;
        }
        return sum;
    }
};