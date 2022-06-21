class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<>>heap;
        int cnt=0;
        for(int i=1;i<heights.size();i++){
            if(heights[i]<=heights[i-1]) continue;
            if(cnt<ladders){
                heap.push(heights[i]-heights[i-1]);
                cnt++;
            }else{
                heap.push(heights[i]-heights[i-1]);
                if(bricks<heap.top()) return i-1;
                bricks-=heap.top();
                heap.pop();
            }
        }
        return heights.size()-1;
    }
};