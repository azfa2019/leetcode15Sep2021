- 算法:树的遍历
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(n)">
- 众所周知BST中序遍历可以从小到大排序.稍作修改,如果以右左中的顺序遍历,可以从大到小排序
- 需要维护一个后缀和(也可理解为前缀和,因为是从大到小排列),表示从最大数到当前数前一个的和,只需更新当前节点令其加上这个后缀和即可

```
class Solution {
    int sum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->right);
        int x=root->val;
        root->val+=sum;
        sum+=x;
        dfs(root->left);
    }
};
```
