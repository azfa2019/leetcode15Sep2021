class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int>presum{0};
        int sum=0;
        for(int h:hours){
            if(h>8) sum+=1;
            else sum+=-1;
            presum.push_back(sum);
        }
        stack<int>stack;
        for(int i=0;i<presum.size();i++){
            if(stack.empty() || presum[i]<presum[stack.top()]) stack.push(i);
        }
        int ans=0;
        for(int i=presum.size()-1;i>=0;i--){
            while(!stack.empty() && presum[i]>presum[stack.top()]){
                ans=max(ans,i-stack.top());
                stack.pop();
            }
        }
        return ans;
    }
};
// 0 1 2  3
// 9 9 10 7 8
//  9,9,6, 0, 6, 6, 9
//0 1 1 -1 -1 -1 -1 1  find the max width presum[j]-presum[i-1]>0
//0 1 2 1  0  -1.-2 -1 find the max j-i+1, s.t. presum[j]>presum[i-1]
//.           ^. ^
//0            5 6. 
//maintain a decreasing stack
//0 -1  -2
//i0 i5 i6
//0 1 2 1  0  -1.-2 -1 
//ans= 1

//0 -1  
//i0 i5 
//0  1  2  1  0  -1.-2 -1 
//i0 i1 i2 i3 i4 i5 i6 i7
//ans= 1

//0   
//i0  
//0  1  2  1  
//i0 i1 i2 i3 
//ans= 1