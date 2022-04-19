<h2><a href="https://leetcode.com/problems/recover-binary-search-tree/">99. Recover Binary Search Tree</a></h2><h3>Medium</h3><hr><div><p>You are given the <code>root</code> of a binary search tree (BST), where the values of <strong>exactly</strong> two nodes of the tree were swapped by mistake. <em>Recover the tree without changing its structure</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg" style="width: 422px; height: 302px;">
<pre><strong>Input:</strong> root = [1,3,null,null,2]
<strong>Output:</strong> [3,1,null,null,2]
<strong>Explanation:</strong> 3 cannot be a left child of 1 because 3 &gt; 1. Swapping 1 and 3 makes the BST valid.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg" style="width: 581px; height: 302px;">
<pre><strong>Input:</strong> root = [3,1,4,null,null,2]
<strong>Output:</strong> [2,1,4,null,null,3]
<strong>Explanation:</strong> 2 cannot be in the right subtree of 3 because 2 &lt; 3. Swapping 2 and 3 makes the BST valid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 1000]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> A solution using <code>O(n)</code> space is pretty straight-forward. Could you devise a constant <code>O(1)</code> space solution?</div>

解法: 
- 算法: 树的Morris遍历
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(n)">,每个节点/边最多遍历两次(求前驱节点一次,访问一次),空间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(1)">
- 本题要点1为Morris遍历,可以参考[视频讲解1](https://www.youtube.com/watch?v=L5JA-9fwQpI)和[视频讲解2](https://www.youtube.com/watch?v=wGXB9OWhPTg),就会很快理解.
- 注意Y总视频讲解中超时的部分出现于当前节点的子节点有指针指向当前节点本身,形成了环,找前驱节点时会无限循环.可以参考上面第二个视频5:57处.
- 要点2为判断哪两个节点位置错误,这里用first和second记录,需要处理是有一个还是两个逆序对.如果是两个逆序对需交换first和second节点.
