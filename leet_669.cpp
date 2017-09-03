#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void traversal(TreeNode * root, int L, int R)
    {
        if (root == nullptr) return;
        
        TreeNode * t = nullptr;
        
        if (root->left != nullptr && root->left->val < L)
        {
            t = root->left->right;
            root->left->left = nullptr;
            root->left->right = nullptr;
            root->left = t;
            traversal(root, L, R);
        } else traversal(root->left, L, R);
        
        if (root->right != nullptr && root->right->val > R)
        {
            t = root->right->left;
            root->right->left = nullptr;
            root->right->right = nullptr;
            root->right = t;
            traversal(root, L, R);
        } else traversal(root->right, L, R);
    }
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        
        if (root == nullptr) return nullptr;
        TreeNode * t = nullptr;
        
        while (root->val < L || root->val > R)
        {
            if (root->val < L)
            {
                //TreeNode * lc = root->left;
                // consider the memory leak later.
                root->left = nullptr;
                t = root->right;
                root->right = nullptr;
                root = t;
                //trimBST(root, L, R);
            }
            else if (root->val > R)
            {
                // there's a chance that I don't need to consider the valid child.
                // because we can't just go up.
                root->right = nullptr;
                t = root->left;
                root->left = nullptr;
                root = t;
                //trimBST(root, L, R);
            }
        }
        
        traversal(root, L, R);
        
        return root;
    }
};


int main()
{
    Solution obj = Solution();
    TreeNode t1(2);
    TreeNode t2(2);
    TreeNode t3(5);
    TreeNode t4(5);
    TreeNode t5(7);
    
    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;
    
    
    
    
    return 0;
}
