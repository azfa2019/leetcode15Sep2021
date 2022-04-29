解法: 
- 算法: 二分+bfs
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(mn\log C)">,C 为格子的最大高度，mn为格子数
- 此题关键为判断是否到达右下角，以及更新res为mid
```
class Solution {
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};   
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        int l=0,r=1e6,ans=0;
        while(l<r){
            int mid=(l+r)/2;
            queue<pair<int,int>>q;
            q.push({0,0});
            vector<int>seen(m*n);
            seen[0]=1;
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !seen[nx*n+ny] && abs(heights[x][y]-heights[nx][ny])<=mid){
                        q.push({nx,ny});
                        seen[nx*n+ny]=1;
                    }
                }
            }
                                                               if(seen[m*n-1]) ans=mid,r=mid;
                                                               else l=mid+1;
        }
                                                               return ans;
    }
};
```

<h2><a href="https://leetcode.com/problems/path-with-minimum-effort/">1631. Path With Minimum Effort</a></h2><h3>Medium</h3><hr><div><p>You are a hiker preparing for an upcoming hike. You are given <code>heights</code>, a 2D array of size <code>rows x columns</code>, where <code>heights[row][col]</code> represents the height of cell <code>(row, col)</code>. You are situated in the top-left cell, <code>(0, 0)</code>, and you hope to travel to the bottom-right cell, <code>(rows-1, columns-1)</code> (i.e.,&nbsp;<strong>0-indexed</strong>). You can move <strong>up</strong>, <strong>down</strong>, <strong>left</strong>, or <strong>right</strong>, and you wish to find a route that requires the minimum <strong>effort</strong>.</p>

<p>A route's <strong>effort</strong> is the <strong>maximum absolute difference</strong><strong> </strong>in heights between two consecutive cells of the route.</p>

<p>Return <em>the minimum <strong>effort</strong> required to travel from the top-left cell to the bottom-right cell.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex1.png" style="width: 300px; height: 300px;"></p>

<pre><strong>Input:</strong> heights = [[1,2,2],[3,8,2],[5,3,5]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex2.png" style="width: 300px; height: 300px;"></p>

<pre><strong>Input:</strong> heights = [[1,2,3],[3,8,4],[5,3,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex3.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> This route does not require any effort.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>rows == heights.length</code></li>
	<li><code>columns == heights[i].length</code></li>
	<li><code>1 &lt;= rows, columns &lt;= 100</code></li>
	<li><code>1 &lt;= heights[i][j] &lt;= 10<sup>6</sup></code></li>
</ul></div>
