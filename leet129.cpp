// 20170802
// totally mine

class Solution {
public:
    int dfs(TreeNode * node, int val)
    {
        val = val * 10 + node->val;
        if (!(node->left || node->right))
            return val;
        int sum = 0;
        if (node->left)
            sum += dfs(node->left, val);
        if (node->right)
            sum += dfs(node->right, val);
        return sum;
    }
    
    int sumNumbers(TreeNode * root)
    {
        if (!root)
            return 0;
        return dfs(root, 0);
    }
};
