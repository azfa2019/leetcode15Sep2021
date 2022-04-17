<h2><a href="https://leetcode.com/problems/increasing-order-search-tree/">897. Increasing Order Search Tree</a></h2><h3>Easy</h3><hr><div><p>Given the <code>root</code> of a binary search tree, rearrange the tree in <strong>in-order</strong> so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg" style="width: 600px; height: 350px;">
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
<strong>Output:</strong> [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/ex2.jpg" style="width: 300px; height: 114px;">
<pre><strong>Input:</strong> root = [5,1,7]
<strong>Output:</strong> [1,null,5,null,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree will be in the range <code>[1, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul></div>

解法: 
- 算法: 树的遍历
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(n)">
- 因为是从小到大排列,必然是中序遍历,所以关键是遍历的同时构造新的父子关系
- 可以把答案想象成一个链表,维护链表的尾节点即可.并且本题也可以像链表一样引入一个虚拟头节点来处理根节点为空的特殊情况.
```
class Solution {
    TreeNode* tail;
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy=new TreeNode();
        tail=dummy;
        dfs(root);
        return dummy->right;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        root->left=nullptr;
        tail=tail->right=root;
        dfs(root->right);
    }
};
```
