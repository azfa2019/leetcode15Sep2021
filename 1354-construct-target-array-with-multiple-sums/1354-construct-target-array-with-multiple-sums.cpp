typedef long long LL;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        LL sum=0;
        priority_queue<LL> q;
        for(int e:target) {
            sum+=e; 
            q.push(e);
        }
        while(q.top()!=1){
            LL curMax=q.top();q.pop();
            LL otherSum=sum-curMax;
            if(curMax-otherSum<1||otherSum==0) return false;
            LL temp=curMax%otherSum;
            if(temp==0) temp=otherSum;
            q.push(temp);
            sum=sum-curMax+temp;
        }
        return true;
    }
};