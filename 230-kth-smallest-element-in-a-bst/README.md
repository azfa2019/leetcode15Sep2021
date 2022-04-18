<h2><a href="https://leetcode.com/problems/kth-smallest-element-in-a-bst/">230. Kth Smallest Element in a BST</a></h2><h3>Medium</h3><hr><div><p>Given the <code>root</code> of a binary search tree, and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>smallest value (<strong>1-indexed</strong>) of all the values of the nodes in the tree</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg" style="width: 212px; height: 301px;">
<pre><strong>Input:</strong> root = [3,1,4,null,2], k = 1
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg" style="width: 382px; height: 302px;">
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,null,1], k = 3
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?</p>
</div>

解法:
- 算法: 树的遍历
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(k)">,k为第k个最小的数
- 本题只需遍历找到第k个数即可,可以用一个counter,也可以直接--k判断是否为0
- 注意dfs定义为bool类型,可以保证找到答案后马上返回,不用继续找下去.
- followup 不用考虑,超纲了
```
class Solution {
    int k,ans;
public:
    int kthSmallest(TreeNode* root, int _k) {
        k=_k;
        dfs(root);
        return ans;
    }
    bool dfs(TreeNode* root){
        if(!root) return false;
        if(dfs(root->left)) return true;
        if(--k==0) {
            ans=root->val;
            return true;
        }
        return dfs(root->right);
    }
};
``` 
