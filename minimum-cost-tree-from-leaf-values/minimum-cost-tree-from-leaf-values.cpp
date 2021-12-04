class Solution {
    public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<int>nextBig(n,INT_MAX);
        vector<int>prevBig(n,INT_MAX);
        stack<int>stack;
        for(int i=0;i<n;i++){
            if(stack.empty() || arr[stack.top()]>=arr[i]){
                stack.push(i);
            }else{
                while(!stack.empty() && arr[stack.top()]<=arr[i]){
                    nextBig[stack.top()]=arr[i];
                    stack.pop();
                }
                stack.push(i);
            }
        }
        while(!stack.empty()) stack.pop();
        for(int i=0;i<n;i++){
            if(stack.empty() || arr[stack.top()]>=arr[i]){
                if(!stack.empty()) prevBig[i]=arr[stack.top()];
                stack.push(i);
            }else{
                while(!stack.empty() && arr[stack.top()]<=arr[i]){
                    stack.pop();
                }
                if(!stack.empty()) prevBig[i]=arr[stack.top()];
                stack.push(i);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=min(prevBig[i],nextBig[i]);
            if(x!=INT_MAX) ans+=x*arr[i];
        }
        return ans;
    }
};

//1 2 3 4 5 4
//    
//5 4 3 5